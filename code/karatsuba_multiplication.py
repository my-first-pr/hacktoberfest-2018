def multiply(x, y):
    """Karatsuba Multiplication Algorithm."""
    if len(str(x)) == 1 or len(str(y)) == 1:    # base case
        return x * y
    else:
        m = max(len(str(x)), len(str(y)))   # larger of the 2 numbers
        m2 = m // 2 # truncates fractional part of m/2

        a = x // 10**m2 # first half of x
        b = x % 10**m2  # second half of x
        c = y // 10**m2 # first half of y
        d = y % 10**m2  # second half of y

        ac = multiply(a, c) # recursively calculate a*c
        bd = multiply(b, d) # recursively calculate b*d
        ad_plus_bc = multiply(a+b, c+d) - ac - bd

        return (10**(2*m2))*ac + (10**m2)*ad_plus_bc + bd


if __name__ == '__main__':
    n1 = 3141592653589793238462643383279502884197169399375105820974944592
    n2 = 2718281828459045235360287471352662497757247093699959574966967627
    product = multiply(n1, n2)
    print(product)
