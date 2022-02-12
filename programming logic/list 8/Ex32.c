#include <stdio.h>
#include <stdlib.h>

void verifyIsPerfect(int number);

void verifyIsPerfect(int number)
{
    int result = 0, i;

    for (i = 1; i <= (number - 1); i++)
        if (number % i == 0)
            result += i;

    if (result == number)
        printf("é perfeito");
    else
        printf("não é perfeito");
}

int main()
{
    int value;

    scanf("%d", &value);

    verifyIsPerfect(value);

    return 0;
}