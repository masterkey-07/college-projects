#include <stdio.h>

int main()
{
    int n, m, i, I, j;
    double numbers[15][15], result = 1;

    scanf("%d %d %d", &n, &m, &I);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%lf", &numbers[i][j]);

    for (i = 0; i < n; i++)
        result *= numbers[i][I];

    printf("%lf", result);

    return 0;
}
