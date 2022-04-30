#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, i, result = 0;

    scanf("%d", &number);

    for (i = 1; i <= number; i++)
        if (number % i == 0)
            result++;

    if (result == 2)
        printf("sim");
    else
        printf("nao");

    return 0;
}
