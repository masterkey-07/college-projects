#include <stdio.h>

int convertToBinary(int decimal)
{

    if (decimal == 1)
        return 1;
    else
        return (decimal % 2) + (10 * convertToBinary(decimal / 2));
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d", convertToBinary(n));

    return 0;
}
