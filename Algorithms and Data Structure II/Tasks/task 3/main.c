#include <stdio.h>
#include <stdlib.h>

int find_position(int *numbers, int index, int key)
{
    if (index >= 0 && *(numbers + index) > key)
    {
        *(numbers + index + 1) = *(numbers + index);
        return find_position(numbers, index - 1, key);
    }

    return index;
}

void insertion_sort(int *numbers, int index, int length)
{
    int position, key;
    if (index < length)
    {
        key = *(numbers + index);
        position = find_position(numbers, index - 1, key);
        *(numbers + position + 1) = key;
        printf("%d %d %d\n", length - index, key, position + 1);
        insertion_sort(numbers, index + 1, length);
    }
}

int main(int argc, char const *argv[])
{
    int length, i;

    scanf("%d", &length);

    int *numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    insertion_sort(numbers, 1, length);

    for (i = 0; i < length; i++)
        printf("%d ", *(numbers + i));

    return 0;
}
