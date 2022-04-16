#include <stdio.h>
#include <stdlib.h>

int search(int searchNumber, int *numbers, int start, int end)
{
    int half = ((end - start) / 2) + start;

    int numberFound = *(numbers + half);

    int result;

    if (numberFound == searchNumber)
        return 0;
    else if (start >= end)
        return -1;
    else if (searchNumber < numberFound)
        result = search(searchNumber, numbers, start, half - 1);
    else
        result = search(searchNumber, numbers, half + 1, end);

    return result >= 0 ? ++result : -1;
}

int main(int argc, char const *argv[])
{
    int length, searchNumber, *numbers, i, result;

    scanf("%d", &length);

    numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    scanf("%d", &searchNumber);

    result = search(searchNumber, numbers, 0, length - 1);

    if (result >= 0)
        printf("%d", result);
    else
        printf("%d nao foi encontrado", searchNumber);

    return 0;
}
