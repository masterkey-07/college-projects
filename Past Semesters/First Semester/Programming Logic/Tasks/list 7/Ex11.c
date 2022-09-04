#include <stdio.h>
#include <string.h>

int main()
{
    char prhase[30];
    int i, bool = 0;

    for (i = 29; i >= 0; i--)
        scanf("%c", &prhase[i]);

    for (i = 0; i <= 29; i++)
    {
        if (prhase[i] == '\n')
        {
            bool = 1;
            continue;
        }

        if (bool == 1)
            printf("%c", prhase[i]);
    }

    return 0;
}
