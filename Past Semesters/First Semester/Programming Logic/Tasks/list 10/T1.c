#include <stdio.h>

void convertToBinary(int decimal)
{

    if (decimal == 1)
        printf("1");
    else if (decimal == 0)
        printf("0");
    else
    {
        convertToBinary(decimal / 2);

        printf("%d", decimal % 2);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    convertToBinary(n);

    return 0;
}
