#include <stdio.h>

int readInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

int compareMax(int numberA, int numberB)
{
    if (numberA >= numberB)
        return numberA;
    else
        return numberB;
}

int main()
{
    int result, number, i, numbers[100];

    number = readInt();

    for (i = 0; i < number; i++)
        numbers[i] = readInt();

    result = numbers[0];

    for (i = 1; i < number; i++)
        result = compareMax(result, numbers[i]);

    printf("%d", result);

    return 0;
}
