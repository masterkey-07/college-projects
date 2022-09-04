#include <stdio.h>
#include <stdlib.h>
int main()
{
    int valor, resultado, i;

    resultado = 0;

    scanf("%d", &valor);

    for (i = 1; i <= valor; i++)
        if ((i * (i + 1) * (i + 2)) == valor)
            resultado = 1;

    if (resultado == 1)
        printf("sim");
    else
        printf("nao");
    return 0;
}