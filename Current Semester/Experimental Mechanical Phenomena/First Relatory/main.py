import math


def std(dados):
    soma = 0
    tamanho = len(dados)

    for x in dados:
        soma += x

    return round(soma / tamanho, 4)


def stddev(dados):
    media = std(dados)
    tamanho = len(dados)

    soma = 0

    for x in dados:
        soma += (x - media) ** 2

    divisao = soma / tamanho

    return round(math.sqrt(divisao), 4)


# Prática A

# Comprimento (A1 - A)
length_data = [
    ['mm', 298.0, 297.0, 298.0, 298.0, 298.0],
    ['cm', 29.6, 29.7, 29.8, 29.7, 29.5],
    ['dm', 2.8, 2.8, 2.9, 2.9, 2.9],
    ['polegada', 11.7, 11 + (4/5), 11 + (4/5), 11.7, 11.7]
]

# Largura (A1 - B)
width_data = [
    ['mm', 210.0, 211.0, 210.0, 211.0, 210.0],
    ['cm', 21.0, 21.0, 21.0, 21.1, 21.0],
    ['dm', 2.1, 2.1, 2.2, 2.1, 2.2],
    ['polegada', 8.3, 8.3, 8.3, 8.3, 8.3]
]

# Prática B

# Dimensão da Peça (B1 - A)
# delta = 0,005

dimension_data = [
    ['d1', 0.310, 0.320, 0.320, 0.320, 0.320],
    ['d2', 3.400, 3.310, 3.400, 3.410, 3.400],
    ['L', 0.680, 0.700, 0.550, 0.680, 0.680]
]

# Massa da Peça (B2 - A)
weight_data = [['massa', 49.97, 49.98, 49.98, 49.98, 49.97]]


# Prática C

# Medida da Espessura da Folha de Sulfite (C1 - A)
paper_thickness_data = [['medida', 0.090, 0.090, 0.095, 0.075, 0.095]]

# Medida da Espessura do Fio de Cabelo (C1 - B)

hair_thickness_data = [['medida', 0.050, 0.050, 0.050, 0.050, 0.050]]


datas = [
    ['length_data', length_data],
    ['width_data', width_data],
    ['dimension_data', dimension_data],
    ['weight_data', weight_data],
    ['paper_thickness_data', paper_thickness_data],
    ['hair_thickness_data', hair_thickness_data]
]


for label, data in datas:
    print(label)

    for row in data:
        title = row[0]
        values = row[1:]
        print('\t', title, std(values), stddev(values))
