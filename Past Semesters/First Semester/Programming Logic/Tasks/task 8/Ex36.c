#include <stdio.h>

int main()
{
    int n = 0, i, j, count;

    scanf("%d", &n);

    int numbers[n][n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &numbers[i][j]);

    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if (numbers[i][j] != 0)
                count++;

        for (j = 0; j < n; j++)
            if (numbers[j][i] != 0)
                count++;

        if (count != 2)
        {
            printf("A não é uma matriz de permutação");
            return 0;
        }
    }

    printf("A é uma matriz de permutação");

    return 0;
}
