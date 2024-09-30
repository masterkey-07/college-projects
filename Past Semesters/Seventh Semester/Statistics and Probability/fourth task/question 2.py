from binom import *

P = 0.8
N = 3

def Y(X):
    return (2 * X) + 1


print('a:', prob_binom(N,0,P))
print('b:', prob_binom(N,1,P))
print('c:', prob_binom(N,2,P))
print('d:', prob_binom(N,3,P))
print('e:', 0.0000)
print('f:', prob_binom(N,0,P))
print('g:', prob_binom(N,1,P))
print('h:', prob_binom(N,2,P))
print('i:', prob_binom(N,3,P))
print('j:', avg_binom(n=N, p=P))
print('k:', var_binom(n=N,p=P))
print('l:', std_dev_binom(n=N,p=P))
print('j:', avg_binom(n=N, p=P))
print('k:', var_binom(n=N,p=P))
print('l:', std_dev_binom(n=N,p=P))

E_Y = sum([Y(x)*prob_binom(N,x,P) for x in range(0,4)])

print('m:', E_Y)

V_Y = sum([((Y(x) - E_Y)**2) * prob_binom(N,x,P) for x in range(0,4)])

print('n:', V_Y, var_binom(n=N,p=P) * 4)

print('o:', round(sqrt(V_Y),4))
