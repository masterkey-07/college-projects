from math import sqrt

P = 0.48
Q = 1 - P
N = 5

X = [0.038, 0.1755, 0.324, 0.299, 0.138, 0.0255]

print("hi")

def f(n):
    r = 1

    for i in range(1, n+1):
        r = r * i

    return r

def b(n,x):
    return f(n) / (f(x) * f(n-x))

def db(n,x,p):
    return b(n,x) * (p**x) * ((1-p)**(n-x))

def r(v):
    return round(v,4)

print("a:", r(db(N,3,P)))
print("b:", 1 - (X[0] + X[1])) 
print("c:", r(N*P))
print("d:", r(N*P*Q))
print("e:", r(sqrt(N*P*Q)))
