#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

typedef char *string;

void heapfiy(string *strings, int *numbers, int length, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max;
    if ((left < length) && (strcmp(strings[numbers[left]], strings[numbers[i]]) > 0))
        max = left;
    else
        max = i;

    if ((right < length) && (strcmp(strings[numbers[right]], strings[numbers[max]]) > 0))
        max = right;

    if (max != i)
    {
        numbers[i] += numbers[max];
        numbers[max] = numbers[i] - numbers[max];
        numbers[i] -= numbers[max];

        heapfiy(strings, numbers, length, max);
    }
}

void build_heap(string *strings, int *numbers, int length)
{
    int i;

    for (i = (length / 2) - 1; i >= 0; i--)
        heapfiy(strings, numbers, length, i);
}

int extract_max(string *strings, int *numbers, int length)
{
    if (length > 0)
    {
        numbers[length] += numbers[0];
        numbers[0] = numbers[length] - numbers[0];
        numbers[length] -= numbers[0];

        heapfiy(strings, numbers, length, 0);
    }

    return numbers[length];
}

int *heap_sort(string *strings, int *numbers, int length)
{
    int *output = (int *)malloc(sizeof(int) * length);

    build_heap(strings, numbers, length);

    while (length >= 0)
        output[--length] = extract_max(strings, numbers, length);

    return output;
}

int verify_string(string str)
{
    int i = -1;
    while (str[++i])
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return 0;

    return TRUE;
}

void free_strings(string *strings, int length)
{
    int i;
    for (i = 0; i < length; i++)
        free(strings[i]);
}

void print_strings(string *strings, int *numbers, int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%s ", strings[numbers[i]]);
}

int main(int argc, char const *argv[])
{

    int length, numbers_string, i, error = -1;
    string *strings;

    scanf("%d", &numbers_string);

    strings = (string *)malloc(sizeof(string) * numbers_string);

    for (i = 0; i < numbers_string; i++)
    {
        strings[i] = (string)malloc(sizeof(char) * 20);
        scanf("%s", strings[i]);

        if (verify_string(strings[i]) != TRUE && error == -1)
            error = i;
    }

    scanf("%d", &length);

    int *numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    if (error >= 0)
    {
        printf("a palavra %seh invalida", strings[error]);

        free_strings(strings, numbers_string);

        free(numbers);

        return 0;
    }

    printf("build_heap: ");
    print_strings(strings, numbers, length);
    printf("\n");

    numbers = heap_sort(strings, numbers, length);

    printf("palavras: ");
    print_strings(strings, numbers, length);

    free_strings(strings, numbers_string);

    free(strings);

    free(numbers);

    return 0;
}
