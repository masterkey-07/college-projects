#include <stdio.h>

//Ordem Alfabetica

struct Pessoa

{

    char nome[50];

    int telefone;
};

int main()

{

    //variaveis

    int n, contador, contador2;

    char auxiliar[50];

    struct Pessoa pessoa[100];

    //scanf

    scanf("%d", &n);

    for (contador = 0; contador < n; contador++)

    {

        scanf("%s %d", &pessoa[contador].nome, &pessoa[contador].telefone);
    }

    for (contador = 1; contador <= n; contador++)

    {

        for (contador2 = 1; contador2 <= n; contador2++)

        {

            if (strcmp(pessoa[contador2 - 1].nome, pessoa[contador2].nome) > 0)

            {

                strcpy(auxiliar, pessoa[contador2 - 1].nome);

                strcpy(pessoa[contador2 - 1].nome, pessoa[contador2].nome);

                strcpy(pessoa[contador2].nome, auxiliar);
            }
        }
    }

    //printf

    for (contador = 0; contador < n; contador++)

    {

        printf("%s %d\n", pessoa[contador].nome, pessoa[contador].telefone);
    }

    return 0;
}