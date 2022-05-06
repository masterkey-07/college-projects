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

struct Value *get_half(struct Value *first, int length)
{
    if (length > 0)
        return get_half(first->nextValue, length - 1);

    return first;
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
    printf("values : ");
    print_values(first);
    printf("\n");
    int half_length = length / 2;

    printf("Length %d\n", length);

    if (length > 0 && first != NULL)
    {
        struct Value *half;

        if (first == NULL)
            printf("OPA\n");

        half = get_half(first->nextValue, half_length - 1);

        printf("LEFT SIDE\n");
        first = merge_sort(first, half_length);

        printf("RIGHT SIDE\n");
        half = merge_sort(half, half_length);

        if (first != NULL && half != NULL)
            printf("Merging Both : %d, %d\n", first->value, half->value);
        else if (first != NULL)
            printf("Merging Left %d\n", first->value);
        else if (half != NULL)
            printf("Merging Rigth %d\n", half->value);

        first = merge(first, half);
        printf("After Merge\n");
        printf("values : ");
        print_values(first);
        printf("\n");

        return first;
    }
    else if (first != NULL)
    {
        printf("Last Node : %d\n", first->value);
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

    print_values(first);
    printf("\n");

    first = merge_sort(first, length - 1);

    print_values(first);

    return 0;
}
