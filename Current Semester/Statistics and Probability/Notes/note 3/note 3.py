dado = [1, 2, 3, 4, 5, 6]

possibilidades = []

for valorA in dado:
    for valorB in dado:
        possibilidades.append((valorA, valorB))


def verificar_A(caso):
    return (caso[0] + caso[1]) % 2 == 0


def verificar_B(caso):
    return caso[0] % 2 == 1


def calcular_prob(valor):
    return round((valor / len(possibilidades)) * 100, 2)


casos_A = []
casos_B = []

for possibilidade in possibilidades:
    if verificar_A(possibilidade):
        casos_A.append(possibilidade)

    if verificar_B(possibilidade):
        casos_B.append(possibilidade)

PA = calcular_prob(len(casos_A))

PB = calcular_prob(len(casos_B))

soma = 0

for caso in casos_A:
    soma += 1 if caso in casos_B else 0

PAB = calcular_prob(soma)

print(PA + PB - PAB)
