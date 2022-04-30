#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberA, numberB, result = 0, positivo = 1, i;

    scanf("%d %d", &numberA, &numberB);

    if (numberB < 0)
    {
        positivo = 0;
        numberB = -numberB;
    }

    for (i = 1; i <= numberB; i++)
    {
        result += numberA;
    }

    if (positivo == 0)
        result = -result;

    printf("%d", result);

    return 0;
}
