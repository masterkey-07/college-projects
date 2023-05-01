import matplotlib.pyplot as plt


def boxplot(data, filename):
    fig, ax = plt.subplots()
    ax.boxplot(data)
    ax.set_title('Box Plot')
    ax.set_ylabel('Valores')
    plt.savefig(filename, format="pdf")
    plt.close(fig)


dados = [13, 9, 18, 15, 14, 21, 7, 10, 11, 20, 5, 18, 37, 16, 17]

boxplot(dados, "BoxPlot2_VictorJorgeCarvalhoChaves_156740.pdf")
