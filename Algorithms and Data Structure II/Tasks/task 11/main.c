#include <stdio.h>
#include <stdlib.h>

struct list
{
    int value;
    struct list *next;
};

typedef struct list list;

int h(int value, int m)
{
    return value % m;
}

list *remove_item(list *row, int value, int *found)
{
    list *output;
    if (row != NULL)
    {
        if (row->value == value)
        {
            *found = 1;

            output = row->next;

            free(row);

            return output;
        }
        else
        {
            row->next = remove_item(row->next, value, found);

            return row;
        }
    }

    return NULL;
}

list *insert_item(list *row, int value)
{
    list *item;
    if (row != NULL)
    {
        row->next = insert_item(row->next, value);

        return row;
    }
    else
    {
        item = (list *)malloc(sizeof(list));

        item->value = value;

        item->next = NULL;

        return item;
    }
}

int main(int argc, char const *argv[])
{
    int length, value, index;

    scanf("%d", &length);

    list **table = (list **)malloc(sizeof(list *) * length);

    list *row;

    value = 0;

    while (1)
    {
        scanf("%d", &value);

        if (value < 0)
            break;

        index = h(value, length);

        table[index] = insert_item(table[index], value);
    }

    scanf("%d", &value);

    index = h(value, length);

    int result = -1;

    table[index] = remove_item(table[index], value, &result);

    if (result == -1)
        printf("Valor nao encontrado\n");

    scanf("%d", &value);

    printf("[%d] ", value);

    row = table[value];

    while (row != NULL)
    {
        printf("%d ", row->value);
        row = row->next;
    }

    return 0;
}

// Valor não encontrado
//[1] 21066 20300