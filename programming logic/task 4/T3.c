#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberA, numberB;

    scanf("%d %d", &numberA, &numberB);

    printf("%d", (numberA % numberB) + (numberA / numberB));

    return 0;
}