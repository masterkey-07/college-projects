#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberA, numberB;

    scanf("%d %d", &numberA, &numberB);

    if ((numberA + numberB) > 20)
        printf("%d", numberA + numberB + 8);
    else
        printf("%d", numberA + numberB - 5);

    return 0;
}
