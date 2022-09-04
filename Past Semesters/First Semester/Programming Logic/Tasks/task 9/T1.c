#include <stdio.h>

int isPrimeNumber(int number)
{
    int i, r = 0;

    for (i = 1; i <= number; i++)
        if (number % i == 0)
            r++;

    return !(r > 2);
}

int main()
{
    int n;

    scanf("%d", &n);

    if (isPrimeNumber(n))
        printf("sim");
    else
        printf("nao");

    return 0;
}
