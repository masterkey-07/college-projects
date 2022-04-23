#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valorA, valorB, valorC;

    scanf("%d %d %d", &valorA, &valorB, &valorC);

    if (valorA == valorB && valorA == valorC)
        printf("equilatero");
    else if (valorA < valorC + valorB && valorB < valorC + valorA && valorC < valorA + valorB)
        if (valorA == valorB || valorA == valorC || valorB == valorC)
            printf("isoceles");
        else
            printf("escaleno");
    else
        printf("invalido");

    return 0;
}