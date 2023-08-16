from functions import calcular_desvio_padrao, calcular_media, calcular_aceleracao
from data import lista_dados
from matplotlib import pyplot as plt

tamanho_inicial = 50

tamanho = 0

medias = []
desvios = []
grav_medias = []
grav_medias_pos = []
grav_medias_neg = []
tamanhos = []

for i in range(len(lista_dados)):
    tamanho += tamanho_inicial
    tamanhos.append(tamanho)

    dados = lista_dados[i]

    media = calcular_media(dados)
    desvio = calcular_desvio_padrao(dados)

    grav_media = calcular_aceleracao(tamanho, media)
    grav_media_pos = calcular_aceleracao(tamanho, media + desvio)
    grav_media_neg = calcular_aceleracao(tamanho, media - desvio)

    print(f'linha {i + 1}, {grav_media} ,{grav_media_pos}, {grav_media_neg}')

    medias.append(media)
    desvios.append(desvio)
    grav_medias.append(grav_media)
    grav_medias_pos.append(grav_media_pos)
    grav_medias_neg.append(grav_media_neg)


grav_medias_media = calcular_media(grav_medias)

lalala = []

for _ in range(len(grav_medias)):
    lalala.append(grav_medias_media)

fig, ax = plt.subplots()

ax.scatter(tamanhos, grav_medias, marker='s', label='acelação da gravidade')
ax.scatter(tamanhos, grav_medias_pos, marker='s',
           label='acelação da gravidade (mais desvio)')
ax.scatter(tamanhos, grav_medias_neg, marker='s',
           label='acelação da gravidade (menos desvio)')
ax.plot(tamanhos, lalala, marker='o',
        label='média da acelação da gravidade', c='r')


ax.set_title('Gráfico de Dispersão')
ax.set_xlabel('Distancia (milimetros)')
ax.set_ylabel('Aceleração (m/s²)')

plt.legend(loc='lower right')
plt.savefig('image.png')
plt.close(fig)
