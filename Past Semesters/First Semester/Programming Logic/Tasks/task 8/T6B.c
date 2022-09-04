#include <stdio.h>
#include <stdlib.h>

//desafio 02 tarefa08 Matrizes
int main()
{
    //variavel
    int ordem, contador, contador2, final = 0, soma = 0, somaAuxiliar = 0, negativo = 0;
    int matriz[100][100];

    scanf("%d", &ordem);

    //scan
    for (contador = 0; ordem > contador; contador++)
        for (contador2 = 0; ordem > contador2; contador2++)
            scanf("%d", &matriz[contador][contador2]);

    //logica soma
    for (contador = 0; ordem > contador; contador++)
    {
        somaAuxiliar = somaAuxiliar + matriz[0][contador];
    }
    for (contador2 = 0; ordem > contador2; contador2++)
    {
        soma = 0;
        for (contador = 0; ordem > contador; contador++)
        {
            soma = soma + matriz[contador][contador2];
        }

        if (somaAuxiliar != soma)
        {
            printf("%d", negativo);
            return 0;
        }
    }

    for (contador = 0; ordem > contador; contador++)
    {
        soma = 0;
        for (contador2 = 0; ordem > contador2; contador2++)
            soma = soma + matriz[contador][contador2];

        if (somaAuxiliar != soma)
        {
            printf("%d", negativo);
            return 0;
        }
    }

    soma = 0;

    for (contador = 0; ordem > contador; contador++)
        soma = soma + matriz[contador][(ordem - contador) - 1];

    if (somaAuxiliar != soma)
    {
        printf("%d", negativo);
        return 0;
    }

    soma = 0;

    for (contador = 0; ordem > contador; contador++)
        soma = soma + matriz[contador][contador];

    if (somaAuxiliar != soma)
    {
        printf("%d", negativo);
        return 0;
    }

    //saida
    printf("%d", somaAuxiliar);

    return 0;
}