from random import *
from math import *
def estimate_pi():
    darts = eval(input('How many times do you want to throw darts: '))
    n = 0
    for i in range(darts):
        x = uniform(-1,1)
        y = uniform(-1,1)
        if x**2 + y**2 <=1:
            n = n + 1
    print('estimate of pi is',4*n/darts)
    print('you are close as',abs(pi-4*n/darts))

estimate_pi()
    
    
