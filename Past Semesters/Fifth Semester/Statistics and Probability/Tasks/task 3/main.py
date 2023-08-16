import math


def fat(x):
    res = 1
    for y in range(x):
        res *= (y + 1)

    return res


def binom(n, k):
    n_f = fat(n)
    k_f = fat(k)
    nk_f = fat(n-k)

    return n_f / (k_f * nk_f)


# p = 0.8
# q = 1 - p
# n = 20
# x = 15

# print(binom(n, x) * (p**x) * (q ** (n - x)))


print(math.e ** -1)
