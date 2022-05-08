from os import system
from math import sqrt


def clear():
    system("clear")


def calc_v(values):
    sum = 0
    for value in values:
        sum += value ** 2
    return sqrt(sum)


def calc_d(valuesA, valuesB):
    newValues = []
    for a, b in zip(valuesA, valuesB):
        newValues.append((a-b)**2)
    return calc_v(newValues)


def look_paralel(valuesA, valuesB):
    k = valuesA[0]/valuesB[0]
    for a, b in zip(valuesA, valuesB):
        if not k == a/b:
            return False
    return True


def calc_prod(valuesA, valuesB):
    sum = 0
    for a, b in zip(valuesA, valuesB):
        sum += (a*b)
    return sum


def calc_comp(valuesA, valuesB):
    prod = calc_prod(valuesA, valuesB)

    vet = calc_v(valuesB) ** 2

    for i in range(len(valuesB)):
        valuesB[i] = valuesB[i] * (prod/vet)

    return valuesB


def minus(valuesA, valuesB):
    output = []
    for a, b in zip(valuesA, valuesB):
        output.append(a-b)
    return output


def multiple(valuesA, valuesB):
    output = []
    for a, b in zip(valuesA, valuesB):
        output.append(a*b)
    return output


v1 = [2, 1, 1]
v2 = [5, 4, 2]


print(multiple(v1, v2))
