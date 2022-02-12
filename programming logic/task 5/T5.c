#include <stdio.h>
#include <stdlib.h>

int main()
{

    int valorA, valorB;

    char sinal;

    scanf("%c %d %d", &sinal, &valorA, &valorB);

    if (sinal == '+')
        printf("%d", valorA + valorB);
    else if (sinal == '-')
        printf("%d", valorA - valorB);
    else if (sinal == '*')
        printf("%d", valorA * valorB);
    else if (sinal == '/')
        if (valorB == 0)
            printf("Divisao por zero.");
        else
            printf("%d,%d", (valorA / valorB), valorA % valorB);
    else
        printf("Operaçao invalida");

    return 0;
}