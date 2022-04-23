#include <stdio.h>
#include <string.h>

struct Filme
{
    char nome[30];
    int ano;
    double duracao;
};

struct Diretor
{
    char nome[30];
    int quantidadeFilmes;
    struct Filme filmes[50];
};

int main()
{
    int i, M, N, j;
    struct Diretor diretores[50];
    char nome[30];

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%s %d", &diretores[i].nome, &diretores[i].quantidadeFilmes);

        for (j = 0; j < diretores[i].quantidadeFilmes; j++)
            scanf("%s %d %lf", &diretores[i].filmes[j].nome, &diretores[i].filmes[j].ano, &diretores[i].filmes[j].duracao);
    }

    while (1 == 1)
    {
        scanf("%s", &nome);
        if (nome[0] == ' ' || nome[0] == '\n')
            for (i = 0; i < N; i++)
            {
                if (strcmp(diretores[i].nome, nome) == 0)
                {
                    for (j = 0; j < diretores[i].quantidadeFilmes; j++)
                        printf("%s %d %lf\n", diretores[i].filmes[j].nome, diretores[i].filmes[j].ano, diretores[i].filmes[j].duracao);

                    break;
                }
                else if (i == N - 1)
                    return 0;
            }
    }

    return 0;
}