a = [0.221, 0.25]
b = [0.222, 0.25]
c = [0.49, 0.46]
d = [0.49, 0.4999]
e = [0.49, 0.4999]

tres_molas = [
    lambda i:[a[i], 4],
    lambda i:[a[i] + b[i], 8],
    lambda i:[d[i], 10],
    lambda i:[a[i] + d[i], 14],
    lambda i:[a[i] + b[i] + d[i], 18],
    lambda i:[a[i] + b[i] + d[i] + e[i], 28],
    lambda i:[c[i], 10],
]


duas_molas = [
    lambda i: [a[i], 23],
    lambda i: [a[i] + b[i], 56],
    lambda i: [d[i], 62],
    lambda i: [a[i] + d[i], 90],
    lambda i: [a[i] + b[i] + d[i], 113],
    lambda i: [a[i] + b[i] + d[i] + e[i], 178],
    lambda i: [c[i], 62],
]


uma_mola = [
    lambda i: [a[i], 15],
    lambda i: [a[i] + b[i], 30],
    lambda i: [d[i], 32],
    lambda i: [a[i] + d[i], 46],
    lambda i: [a[i] + b[i] + d[i], 60],
    lambda i: [a[i] + b[i] + d[i] + e[i], 91],
    lambda i: [c[i], 31],
]


def calcular_k(caso, i):
    n, x = caso(i)

    return round(n / (x / 1000), 2)


def printar_caso(caso):
    print('balaca', calcular_k(caso, 0))
    print('dinanometro', calcular_k(caso, 1))


for i in range(len(uma_mola)):
    print('caso ', i + 1)
    printar_caso(uma_mola[i])
