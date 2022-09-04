#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *numbers, int length)
{
    int i, j, number;

    for (i = 0; i < length; i++)
        for (j = 0; j < length - i; j++)
            if (*(numbers + j) > *(numbers + j + 1))
            {
                number = *(numbers + j);
                *(numbers + j) = *(numbers + j + 1);
                *(numbers + j + 1) = number;
            }
}

int main(int argc, char const *argv[])
{
    int length, i;

    scanf("%d", &length);

    int *numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    bubble_sort(numbers, length);

    for (i = 0; i < length; i++)
        printf("%d ", *(numbers + i));

    return 0;
}
