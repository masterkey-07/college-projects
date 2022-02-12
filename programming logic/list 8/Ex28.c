#include <stdio.h>
#include <math.h>

int binarySize(int value)
{
    int i;

    for (i = 0; i < value; i++)
        if (value < pow(2, i))
            return i;

    return 1;
}

void convertToBinary(int value)
{
    int size, i;
    size = binarySize(value);
    char binary[size];

    for (i = size - 1; i >= 0; i--)
    {
        if (value % 2 == 0)
            binary[i] = '0';
        else
            binary[i] = '1';

        value /= 2;
    }

    for (i = 0; i < size; i++)
        printf("%c", binary[i]);
}

int main()
{
    int value, i;

    scanf("%d", &value);

    convertToBinary(value);

    return 0;
}
