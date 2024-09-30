from math import sqrt

def __factory(n):
    r = 1
    for i in range(1, n+1):
        r = r * i
    return r

def __binom(n,x):
    return __factory(n) / (__factory(x) * __factory(n-x))

def prob_binom(n:int,x:int,p:int):
    return __round_4(__binom(n,x) * (p**x) * ((1-p)**(n-x)))

def __round_4(value):
    return round(value,4)

def avg_binom(n,p):
    return __round_4(n * p)

def var_binom(n,p):
    return __round_4(n * p * (1-p))

def std_dev_binom(n,p):
    return __round_4(sqrt(var_binom(n,p)))