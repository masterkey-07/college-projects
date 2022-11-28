#include <stdio.h>
#include <stdlib.h>

#define FALSE 1
#define TRUE 2

struct Tree
{
    int column;
    int line;

    struct Tree *nodes;
};

typedef struct Tree Tree;

void **organization_possibilites(int index, int *memory, int columns)
{
    if (index >= columns)
    {
        for (int i = 0; i < columns; i++)
            printf("%d ", memory[i] + 1);

        printf("\n");
    }

    int *possibilities = (int *)malloc(sizeof(memory));

    for (int i = 0; i < index; i++)
        possibilities[memory[i]] = FALSE;

    for (int i = 0; i < columns; i++)
    {
        if (possibilities[i] != FALSE)
        {
            memory[index] = i;
            organization_possibilites(index + 1, memory, columns);
        }
    }
}

int main(int argc, char const *argv[])
{
    int length = 3;

    int *memory = malloc(sizeof(int) * length);

    organization_possibilites(0, memory, length);

    return 0;
}
