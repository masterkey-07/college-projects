#include <stdio.h>
#include <stdlib.h>

void heapfiy(int *numbers, int length, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max;
    if ((left < length) && (numbers[left] > numbers[i]))
        max = left;
    else
        max = i;

    if ((right < length) && (numbers[right] > numbers[max]))
        max = right;

    if (max != i)
    {
        numbers[i] += numbers[max];
        numbers[max] = numbers[i] - numbers[max];
        numbers[i] -= numbers[max];

        heapfiy(numbers, length, max);
    }
}

void build_heap(int *numbers, int length)
{
    int i;

    for (i = (length / 2) - 1; i >= 0; i--)
        heapfiy(numbers, length, i);
}

int extract_max(int *numbers, int length)
{
    if (length > 0)
    {
        numbers[length] += numbers[0];
        numbers[0] = numbers[length] - numbers[0];
        numbers[length] -= numbers[0];

        heapfiy(numbers, length, 0);
    }

    return numbers[length];
}

int *heap_sort(int *numbers, int length)
{
    int *output = (int *)malloc(sizeof(int) * length);

    build_heap(numbers, length);

    while (length >= 0)
        output[--length] = extract_max(numbers, length);

    return output;
}

int main(int argc, char const *argv[])
{
    int length, i;

    scanf("%d", &length);

    int *numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    numbers = heap_sort(numbers, length);

    for (i = 0; i < length; i++)
        printf("%d ", *(numbers + i));

    return 0;
}
