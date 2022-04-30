#include <stdio.h>

int main()
{
    char prhase[100];
    int i, count = 0;

    for (i = 0; i < 100; i++)
        scanf("%c", &prhase[i]);

    for (i = 0; i < 100; i++)
        if (prhase[i] == '\n')
            break;

    printf("%d", i);
    return 0;
}
