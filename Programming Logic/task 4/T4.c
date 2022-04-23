#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;

    scanf("%d", &number);

    printf("%d", ((number % 100) - (number % 10)) / 10);

    return 0;
}