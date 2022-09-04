#include <stdio.h>
#include <limits.h>

int main()
{
    int m, n, numbers[100][100], number, i, j, rI, rJ;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &numbers[i][j]);

    number = INT_MAX;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (numbers[i][j] < number)
            {
                number = numbers[i][j];
                rI = i;
            }

    number = INT_MIN;

    for (i = 0; i < n; i++)
        if (numbers[rI][i] > number)
        {
            number = numbers[rI][i];
            rJ = i;
        }

    printf("%d %d", rI, rJ);
    return 0;
}
