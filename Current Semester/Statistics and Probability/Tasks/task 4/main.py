import math


def get_z(x, u, s):
    return (x - u)/s


def fdp_normal(x, u, s):

    z = get_z(x, u, s)
    a = 1 / (s * (math.sqrt(2 * math.pi)))
    b = - (z**2)/2

    return a * (math.e ** b)


sum = 0


for i in range(99, 102):
    sum += fdp_normal(i, 100, 1)


print(sum)
