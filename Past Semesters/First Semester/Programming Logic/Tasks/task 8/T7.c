#include <stdio.h>

int main()
{
    int m, n, k, i, j, shootX[10000], shootY[10000], result = 0, x, y;
    char table[100][100];

    scanf("%d %d ", &m, &n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%c ", &table[i][j]);

    scanf("%d", &k);

    for (i = 0; i < k; i++)
        scanf("%d %d", &shootX[i], &shootY[i]);

    for (i = 0; i < k; i++)
    {
        x = shootX[i] - 1;
        y = shootY[i] - 1;

        if (table[x][y] == '#')
        {
            if (table[x - 1][y] == '#' || table[x][y - 1] == '#')
                continue;

            result++;
        }
    }

    printf("%d", result);

    return 0;
}