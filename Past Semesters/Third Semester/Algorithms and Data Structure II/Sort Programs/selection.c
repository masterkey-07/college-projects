#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *numbers, int length)
{
    int i, j, min_j, number;

    for (i = 0; i < length; i++)
    {
        min_j = i;
        for (j = i + 1; j < length; j++)
            if (*(numbers + j) < *(numbers + min_j))
                min_j = j;

        number = *(numbers + i);
        *(numbers + i) = *(numbers + min_j);
        *(numbers + min_j) = number;
    }
}

int main(int argc, char const *argv[])
{
    int length, i;

    scanf("%d", &length);

    int *numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    selection_sort(numbers, length);

    for (i = 0; i < length; i++)
        printf("%d ", *(numbers + i));

    return 0;
}
