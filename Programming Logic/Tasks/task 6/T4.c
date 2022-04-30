#include <stdio.h>
#include <stdlib.h>
int main()
{

    int valor, resultado, i;

    resultado = 0;

    scanf("%d", &valor);

    for (i = 1; i <= (valor - 1); i++)
        if (valor % i == 0)
            resultado += i;

    if (resultado == valor)
        printf("sim");
    else
        printf("nao");
}