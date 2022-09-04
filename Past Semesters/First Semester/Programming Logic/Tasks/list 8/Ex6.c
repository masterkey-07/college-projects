#include <stdio.h>

int verify(char value)
{
    int i;
    char verifiers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (i = 0; i < 10; i++)
    {
        if (value == verifiers[i])
            return 1;
    }

    return 0;
}

int main()
{
    char value;

    scanf("%c", &value);

    printf("%d", verify(value));

    return 0;
}
