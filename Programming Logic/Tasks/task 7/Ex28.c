#include <stdio.h>

int main()
{

    double a[21], b[21], X[21][21], result[41];
    int n, i, j, k, x, y;

    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < 41; i++)
            result[i] = 0.0;

        scanf("%d", &n);

        for (i = 0; i <= n; i++)
            scanf("%lf", &a[i]);

        for (i = 0; i <= n; i++)
            scanf("%lf", &b[i]);

        for (y = 0; y <= n; y++)
            for (x = 0; x <= n; x++)
                result[x + y] += a[y] * b[x];

        for (i = 0; i <= n + n; i++)
            if (i == 0)
                if (result[i + 1] < 0)
                    printf("%lf", result[i]);
                else
                    printf("%lf+", result[i]);
            else if (n + n == i)
                printf("%lfx^%d\n", result[i], i);
            else if (result[i + 1] < 0)
                printf("%lfx^%d", result[i], i);
            else
                printf("%lfx^%d+", result[i], i);
    }
    return 0;
}