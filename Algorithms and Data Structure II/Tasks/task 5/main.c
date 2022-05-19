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

int quicksort(int *array, int p, int r, int position)
{
    int q, a, b;
    if (p < r)
    {
        q = partition(array, p, r);

        if (q == position)
            return q;
        else if (position < q)
            return quicksort(array, p, q - 1, position);
        else
            return quicksort(array, q + 1, r, position);
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int length, i, position;

    scanf("%d", &position);

    position--;

    scanf("%d", &length);

    int *numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    int result = quicksort(numbers, 0, length - 1, position);

    printf("%do menor elemento eh o %d\n", position + 1, numbers[position]);

    for (i = 0; i < length; i++)
        printf("%d ", *(numbers + i));

    return 0;
}