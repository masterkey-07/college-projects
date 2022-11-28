#include <stdio.h>
#include <stdlib.h>

#define NONE -1
#define FALSE 1
#define TRUE 2

void **organization_possibilites(int column, int *memory, int *free_lines, int *rules, int length)
{
    if (column >= length)
    {
        for (int i = 0; i < length; i++)
            printf("%d ", memory[i] + 1);

        printf("\n");

        return 0;
    }

    int line;

    for (line = 0; line < length; line++)
        if (free_lines[line] != FALSE || line == rules[column])
        {
            memory[column] = line;
            free_lines[line] = FALSE;

            organization_possibilites(column + 1, memory, free_lines, rules, length);

            if (line != rules[column])
                free_lines[line] = TRUE;
        }
}

int main(int argc, char const *argv[])
{
    int length, column, line, number_rules, i;

    scanf("%d %d", &length, &number_rules);

    int *memory = (int *)malloc(sizeof(int) * length);
    int *free_lines = (int *)malloc(sizeof(int) * length);
    int *rules = (int *)malloc(sizeof(int) * length);

    for (i = 0; i < length; i++)
        rules[i] = NONE;

    for (i = 0; i < number_rules; i++)
    {
        scanf("%d %d", &line, &column);
        rules[column - 1] = line - 1;
        free_lines[line - 1] = FALSE;
    }

    organization_possibilites(0, memory, free_lines, rules, length);

    free(memory);
    free(free_lines);
    free(rules);

    return 0;
}
