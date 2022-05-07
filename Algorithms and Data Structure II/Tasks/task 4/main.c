#include <stdio.h>
#include <stdlib.h>

struct Value
{
    struct Value *nextValue;
    int value;
};

struct Value *add_value(struct Value *value, int number)
{
    struct Value *output = (struct Value *)malloc(sizeof(struct Value));

    output->nextValue = NULL;
    output->value = number;

    if (value != NULL)
        value->nextValue = output;

    return output;
}

void print_values(struct Value *value)
{
    if (value != NULL)
    {
        printf("%d ", value->value);
        print_values(value->nextValue);
    }
}

void free_values(struct Value *value)
{
    if (value != NULL)
    {
        free_values(value->nextValue);
        free(value);
    }
}

struct Value *get_half(struct Value *first, int length)
{
    if (length > 0)
        return get_half(first->nextValue, length - 1);
    else if (length == 0)
        return first;
    else
        return NULL;
}

struct Value *merge(struct Value *first, struct Value *half)
{
    if (first != NULL && half != NULL)
    {
        if (first->value < half->value)
        {
            first->nextValue = merge(first->nextValue, half);
            return first;
        }
        else
        {
            half->nextValue = merge(first, half->nextValue);
            return half;
        }
    }
    else if (first != NULL && half == NULL)
        return first;
    else if (first == NULL && half != NULL)
        return half;
    else
        return NULL;
}

struct Value *merge_sort(struct Value *first, int length)
{
    int half_length = length / 2;
    int rest = length % 2;

    if (length > 1 && first != NULL)
    {
        struct Value *half = get_half(first->nextValue, half_length - 1);

        first = merge_sort(first, half_length);

        half = merge_sort(half, half_length + rest);

        return merge(first, half);
    }
    else if (first != NULL)
    {
        first->nextValue = NULL;
        return first;
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    int length, i, output_number;

    struct Value *first, *last;

    scanf("%d", &length);

    scanf("%d", &output_number);

    first = add_value(first, output_number);

    last = first;

    for (i = 0; i < length - 1; i++)
    {
        scanf("%d", &output_number);
        last = add_value(last, output_number);
    }

    first = merge_sort(first, length);

    print_values(first);

    free_values(first);

    return 0;
}
