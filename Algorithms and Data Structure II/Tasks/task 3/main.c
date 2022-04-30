#include <stdio.h>
#include <stdlib.h>

int binary_search(int *numbers, int start, int end, int key)
{
    if (start > end)
        return -1;

    int half = ((end - start) / 2) + start;

    int number = *(numbers + half);

    if (key < number)
    {
        if (start == end)
            return half;

        return binary_search(numbers, start, half, key);
    }
    else
        return binary_search(numbers, half + 1, end, key);
}

void insertion_sort(int *numbers, int index, int length)
{
    int position, key, i;
    if (index < length)
    {
        key = *(numbers + index);

        position = binary_search(numbers, 0, index - 1, key);

        if (position != -1)
        {
            for (i = index; i > position; i--)
                *(numbers + i) = *(numbers + i - 1);

            *(numbers + position) = key;
        }
        else
            position = index;

        printf("%d %d %d\n", length - index, key, position);

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
