"""
This module contains the core Differential Evolution calculations.
"""

import numpy as np
import numpy.random as rnd


def _get_different_indices(vec, idx, amount):
    """
    Get a number of mutual different indicies of an given vector and an index which can not be
    selected.

    :param numpy.ndarray vec:
        An input vector.

    :param int idx:
        An index which can not be amoung the 3 output indices.

    :param int amount:
        The number of different indices desired.

    :return:
        The mutual different indices
    :rtype: numpy.ndarray
    """
    vec_size = vec.shape[0]
    x = np.array([])
    for i in range(amount):
        it_flag = True
        while it_flag:
            candidate = rnd.randint(vec_size)
            if candidate != idx and candidate not in x:
                it_flag = False
                x = np.append(x, candidate)
    # Assuring that output vector has integer values
    x = x.astype(int)
    return x


def _generate_initial_population(dim, low_lim, high_lim, N=50):
    """
    Pseudo-random generation of the initial population.

    :param int dim:
        The number of dimensions of the objective function argument array.

    :param float low_lim:
        The inferior limit of the hypercube search region.

    :param float high_lim:
        The superior limit of the hypercube search region.

    :param int N:
        The number of individuals to be generated.

    :return:
        The population and associated mutation vector
    :rtype: tuple(numpy.ndarray, numpy.ndarray)
    """
    # Generating initial population. In this case, in a square domain.
    population = rnd.uniform(low_lim, high_lim, size=(N, dim))
    mut_vec = np.zeros(population.shape)
    return population, mut_vec


def _check_convergence(solution, tol=1e-8):
    """
    Check if the convergence of DE procedure is achieved using the standard deviation (SD) as criterium.
    If the SD is smaller than an adopted numerical tolerance, the convergence is sinalized as True.

    :param numpy.ndarray solution:
        The solution candidate.

    :param float tol:
        Numerical tolerance of convergence.

    :return:
        A bool indicating if convergence was achieved (True).
    :rtype: bool
    """
    solution_sd = np.std(solution)
    return solution_sd < tol


def optimize(
        fobj, dim, low_limit, high_limit,
        N=100, max_number_of_generations=2000,
        mutation_parameter=0.9, scale_factor=0.5, seed=974378
):
    """
    Differential Evolution calculations. This routine computes a minimum of a given objective function.
    The actual method is only valid for unconstrained optimization problems.

    :param function fobj:
        The objective function.

    :param int dim:
        Number of dimensions of the objective function's argument.

    :param float low_limit:
        The inferior limit of the hypercube search region.

    :param float high_limit:
        The superior limit of the hypercube search region.

    :param int N:
        The number of individuals to be generated.

    :param int max_number_of_generations:
        Max number of generations to be employed by the procedure.

    :param float mutation_parameter:
        A parameter to related to the success' rate of mutations.

    :param float scale_factor:
        A scale factor of linear combination employed in the mutation procedure.

    :param int seed:
        A seed to be employed in the pseudo-random numbers generation.

    :return:
        The solution coordinates, the objective function evaluated at this point,
        the method convergence's flag and the output log message.
    :rtype: tuple
    """

    # Setting the seed
    rnd.seed(seed)

    # Generating the population
    population, mutation_vector = _generate_initial_population(
        dim=dim,
        low_lim=low_limit,
        high_lim=high_limit,
        N=N
    )

    # Setting the tolerance and convergence flag
    flag_convergence = False

    # Initializing generation counter and setting a iteration limiter
    gen = 0

    # Getting best initial solution
    fobj_best = np.inf
    for i in range(N):
        fobj_best_prev = fobj(population[i, :])
        if fobj_best_prev <= fobj_best:
            fobj_best = fobj_best_prev

    # DE loop
    while not flag_convergence and gen < max_number_of_generations:
        gen = gen + 1

        # Loop for mutation procedure over a generation
        for i in range(N):
            gen_idx = _get_different_indices(population, i, 3)
            r1, r2, r3 = gen_idx[0], gen_idx[1], gen_idx[2]
            delta_i = rnd.randint(dim)
            for j in range(dim):
                if rnd.uniform() <= mutation_parameter or j == delta_i:
                    mutation_vector[i, j] = population[r1, j] + scale_factor*(population[r2, j]-population[r3, j])
                else:
                    mutation_vector[i, j] = population[i, j]

        # Loop for surviving procedure over a generation
        conv_current = np.inf
        for i in range(N):
            if fobj(mutation_vector[i, :]) <= fobj(population[i, :]):
                population[i, :] = mutation_vector[i, :]
            conv_candidate = fobj(population[i, :])
            if conv_candidate <= conv_current:
                conv_current = conv_candidate
                idx_sol = i

        solution = population[idx_sol, :]
        fobj_best = fobj(solution)

        flag_convergence = _check_convergence(solution)

    if flag_convergence:
        log_message = f"Convergence achieved within {gen} generations:\n" \
                      f"Solution = {solution}\n" \
                      f"f(x)= {fobj_best}"
    else:
        log_message = f"Number maximum of generations ({max_number_of_generations}) exceed:\n" \
                      f"Solution = {solution}\n" \
                      f"f(x)= {fobj_best}"

    return solution, fobj_best, flag_convergence, log_message
