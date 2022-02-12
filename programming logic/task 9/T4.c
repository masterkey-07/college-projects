#include <stdio.h>

int readInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

void invertArray(int numbers[100], int number)
{
    int i, n;

    for (i = number - 1; i >= 0; i--)
        printf("%d ", numbers[i]);
}

int main()
{
    int result, number, i, numbers[100];

    number = readInt();

    for (i = 0; i < number; i++)
        numbers[i] = readInt();

    invertArray(numbers, number);

    return 0;
}
