#include <stdio.h>

int main()
{
    int m, n, numbers[100][100], i, j, sum;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &numbers[i][j]);

    for (i = 0; i < m; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum += numbers[i][j];

        printf("%d ", sum);
    }

    return 0;
}
