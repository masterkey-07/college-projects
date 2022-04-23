#include <stdio.h>

int main()
{
    int m, n, i, j;
    double numbers[31][21], a = 1.0;
    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &numbers[i][j]);

    for (i = 0; i < m; i++)
    {
        a = 1.0;
        for (j = 0; j < n; j++)
            a *= numbers[i][j];

        numbers[i][j] = a;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%lf ", numbers[i][j]);

        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j <= n; j++)
            printf("%lf ", numbers[i][j]);
        printf("\n");
    }
    return 0;
}
