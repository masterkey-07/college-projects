import matplotlib.pyplot as plt
import pandas as pd
erros = [8, 11, 8, 12, 14, 13, 11, 14, 14, 15, 6, 10, 14, 19, 6, 12, 7, 5, 8, 8, 10, 16, 10,
         12, 12, 8, 11, 6, 7, 12, 7, 10, 14, 5, 12, 7, 9, 12, 11, 9, 14, 8, 14, 8, 12, 10, 12, 22, 7, 15]


def plot_histogram(data):
    df = pd.DataFrame({'Erros': data})
    df.hist(bins=len(data))
    plt.savefig('./out/hist.png')


def plot_bar(data):
    plt.bar(range(len(data)), data)
    plt.title("Quantidade de Erros por Dia")
    plt.xlabel("Numero do Dia")
    plt.ylabel("Erros")
    plt.savefig('./out/bar.png')


plot_bar(erros)

plot_histogram(erros)


def get_key(item):
    if (item < 10):
        return 0

    return (item - (item % 10)) / 10


def plot_leefs(data):
    data = sorted(data)

    arr = []

    key = 0

    for item in data:
        if (key == get_key(item)):
            arr.append(item % 10)
        else:
            print(str(key), '|', arr)
            arr.clear()
            key += 1

            arr.append(item % 10)

    print(str(key), '|', arr)


plot_leefs(erros)
