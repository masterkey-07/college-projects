from pandas import read_csv
from json import dumps


def is_casado(pessoa):
    return pessoa[0] in 'casado'


df_pessoas = read_csv('./data/pessoas.csv', encoding='utf8')

variaveis = [
    ('Estado Civil', lambda pessoa: pessoa[0]),
    ('Região de Procedência', lambda pessoa: pessoa[6]),
    ('Número de Filhos', lambda pessoa: pessoa[2] if is_casado(
        pessoa) else None),
    ('Idade (Anos)', lambda pessoa: pessoa[4])
]

frequencia = {}

for index, pessoa in df_pessoas.iterrows():
    for var, get in variaveis:
        if frequencia.get(var) == None:
            frequencia[var] = {}

        valor = str(get(pessoa))

        if valor == "None":
            continue

        if frequencia[var].get(valor) == None:
            frequencia[var][valor] = 0

        frequencia[var][valor] += 1

print(dumps(frequencia, ensure_ascii=False, indent=4))
