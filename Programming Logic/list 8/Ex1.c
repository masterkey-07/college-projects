
#include <stdio.h>

int powerOf3(int value)
{
    int i, result = 1;

    for (i = 0; i < 3; i++)
        result *= value;

    return result;
}

int main()
{
    int value;

    scanf("%d", &value);

    printf("%d", powerOf3(value));

    return 0;
}
