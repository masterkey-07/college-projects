#include <stdio.h>

int main()
{
    char prhase[100];
    int count = 1, i;

    for (i = 0; i < 100; i++)
        scanf("%c", &prhase[i]);

    for (i = 0; i < 100; i++)
        if (prhase[i] == ' ')
            count++;

    printf("%d", count);
    return 0;
}
