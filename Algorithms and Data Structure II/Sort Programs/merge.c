#include <stdio.h>
#include <stdlib.h>

int merge_sort() {}

int main(int argc, char const *argv[])
{
    int length, i;

    scanf("%d", &length);

    int numbers = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        scanf("%d", numbers + i);

    merge_sort();

    for (i = 0; i < length; i++)
        printf("%d", *(numbers + i));

    return 0;
}
