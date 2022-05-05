#include <stdio.h>
#include <stdlib.h>

struct Value
{
    struct Value *nextValue;
    int value;
};

struct Value *addValue(struct Value *value, int number)
{
    struct Value *output = (struct Value *)malloc(sizeof(struct Value));

    output->nextValue = NULL;
    output->value = number;

    if (value != NULL)
        value->nextValue = output;

    return output;
}

void printValues(struct Value *value)
{
    if (value != NULL)
    {
        printf("%d ", value->value);
        printValues(value->nextValue);
    }
}

int main(int argc, char const *argv[])
{
    int length, i, output_number;

    struct Value *first, *last;

    scanf("%d", &length);

    scanf("%d", &output_number);

    first = addValue(first, output_number);

    last = first;

    for (i = 0; i < length - 1; i++)
    {
        scanf("%d", &output_number);
        last = addValue(last, output_number);
    }

    printValues(first);

    return 0;
}
