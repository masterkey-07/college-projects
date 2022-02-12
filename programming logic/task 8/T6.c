#include <stdio.h>

int main()
{
    int n, numbers[100][100], i, j, result = 0, sum = 0, constSum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &numbers[i][j]);

    for (i = 0; i < n; i++)
        constSum += numbers[0][i];

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum += numbers[i][j];

        if (sum != constSum)
        {
            printf("0");
            return 0;
        }
    }

    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum += numbers[i][j];

        if (sum != constSum)
        {
            printf("0");
            return 0;
        }
    }

    sum = 0;

    for (i = 0; i < n; i++)
        sum += numbers[i][i];

    if (sum != constSum)
    {
        printf("0");
        return 0;
    }

    sum = 0;

    for (i = 0; i < n; i++)
        sum += numbers[i][n - i - 1];

    if (sum != constSum)
    {
        printf("0");
        return 0;
    }

    printf("%d", constSum);

    return 0;
}
