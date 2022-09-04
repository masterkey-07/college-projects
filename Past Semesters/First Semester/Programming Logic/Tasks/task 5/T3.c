#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberA, numberB, numberC;

    scanf("%d %d %d", &numberA, &numberB, &numberC);

    if (numberA > numberB && numberA > numberC)
        printf("%d", numberA);
    else if (numberB > numberA && numberB > numberC)
        printf("%d", numberB);
    else
        printf("%d", numberC);

    return 0;
}
