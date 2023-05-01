import math


def calcular_media(dados):
    soma = 0
    tamanho = len(dados)

    for x in dados:
        soma += x

    return round(soma / tamanho, 4)


def calcular_desvio_padrao(dados):
    media = calcular_media(dados)
    tamanho = len(dados)

    soma = 0

    for x in dados:
        soma += (x - media) ** 2

    divisao = soma / tamanho

    return round(math.sqrt(divisao), 4)


def calcular_aceleracao(dist, time):
    return round((2 * dist) / (time**2)) / 1000


# fig, ax = plt.subplots()

# ax.scatter(tamanhos, medias, label='média')
# ax.scatter(tamanhos, desvios, label='desvio')

# plt.legend(loc="upper left")

# ax.set_title('Gráfico de Dispersão')
# ax.set_xlabel('Distancia (milimetros)')
# ax.set_ylabel('Tempo (segundos)')

# plt.savefig('image.png')
# plt.close(fig)
