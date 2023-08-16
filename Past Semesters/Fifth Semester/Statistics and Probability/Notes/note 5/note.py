from matplotlib import pyplot
from math import sqrt


def save_bar(dados):
    pyplot.bar(range(len(dados)), dados)
    pyplot.xlabel("a")
    pyplot.savefig("bar.png")


dados = [0.20, 0.30, 0.35, 0.05, 0.05, 0.05]

save_bar(dados)

sum = 0

for i in range(len(dados)):
    dado = dados[i]
    sum += ((100 * dado) * i) / 100

pe = round(sum * 10) / 10

sum = 0

for i in range(len(dados)):
    dado = dados[i]
    sum += abs((dado ** 2) - (pe ** 2))

print(sum)

print(sqrt(sum))
