#include <stdio.h>
#include <limits.h>

int main()
{
    int count = 0, i, index, minor = INT_MAX;
    char phrase[100];

    for (i = 0; i < 100; i++)
        scanf("%c", &phrase);

    for (i = 0; i < 100; i++)
    {
        if (phrase[i] == ' ')
        {
            if (minor > count)
            {
                minor = count;
                index = i;
            }

            count = 0;
        }
        else
            count++;

        if (phrase[i] == '\n')
            break;
    }

    for (i = index - minor; i < index; i++)
        printf("%c", phrase[i]);

    return 0;
}
