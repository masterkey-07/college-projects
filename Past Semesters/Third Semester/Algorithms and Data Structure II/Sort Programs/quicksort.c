#include <stdio.h>
#include <stdlib.h>

int partition(int *array, int p, int r)
{
    int x = array[r];
    int i = p - 1;
    int j;
    int value;

    for (j = p; j <= r - 1; j++)
    {
        if (array[j] <= x)
        {
            i++;

            value = array[i];
            array[i] = array[j];
            array[j] = value;
        }
    }

    i++;

    value = array[i];
    array[i] = array[r];
    array[r] = value;

    return i;
}

void quicksort(int *array, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(array, p, r);

        quicksort(array, p, q - 1);
        quicksort(array, q + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int length, i;

    scanf("%d", &length);

    int *numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    quicksort(numbers, 0, length - 1);

    for (i = 0; i < length; i++)
        printf("%d ", *(numbers + i));

    return 0;
}