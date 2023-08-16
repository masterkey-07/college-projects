import matplotlib.pyplot as plt


def calcular_quartil(arr, num):
    porcentagem = num / 4
    tamanho = len(arr)
    posicao = int(round(tamanho * porcentagem))

    soma = 0

    if tamanho % 2 == 0:
        soma += arr[posicao]

    soma += arr[posicao - 1]

    return soma / 2


dados = sorted([4, 2, 3, 4, 11, 8, 5, 15])

print(dados)

tamanho = len(dados)

print(calcular_quartil(dados, 1))
print(calcular_quartil(dados, 2))
print(calcular_quartil(dados, 3))


def boxplot(data, filename):
    fig, ax = plt.subplots()
    ax.boxplot(data)
    ax.set_title('Box Plot')
    ax.set_ylabel('Valores')
    plt.savefig(filename)
    plt.close(fig)


boxplot(dados, "BoxPlot1_VictorJorgeCarvalhoChaves_156740.png")
