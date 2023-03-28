def calcular_quartil(arr, num):
    porcentagem = num / 4
    tamanho = len(arr)
    posicao = int(round(tamanho * porcentagem))

    soma = 0

    if tamanho % 2 == 0:
        soma += arr[posicao]

    soma += arr[posicao - 1]

    return soma / 2


# Quantidade : 36
exemplo = [18, 21, 21, 23, 23, 25, 27, 29, 30, 31, 32, 32, 32, 34, 35, 36, 38,
           41, 42, 42, 43, 44, 45, 46, 46, 47, 48, 50, 54, 56, 57, 58, 60, 62, 98, 116]

# Resolução para ver se em Outliers (em uma Blot box)

# Q1 = 30 + 31 -> 61 -> 30.5
Q1 = calcular_quartil(exemplo, 1)
print('Q1 :', Q1)

# Mediana = Q2 -> 41 + 42 -> 83 -> 41.5
Q2 = calcular_quartil(exemplo, 2)
print('Mediana (Q2) :', Q2)

# Q3 = 48 + 50 -> 98 -> 49.0
Q3 = calcular_quartil(exemplo, 3)
print('Q3 :', Q3)


# AIQ = Q3 - Q1 -> 49 - 30.5 -> 18.5

AIQ = Q3-Q1

print('AIQ :', AIQ)

LI = Q1 - (1.5 * AIQ)

print('Limite Inferior :', LI)

LS = Q3 + (1.5 * AIQ)

print('Limite Superior :', LS)

print('Outliers :', list(filter(lambda x: x < LI or x > LS, exemplo)))
