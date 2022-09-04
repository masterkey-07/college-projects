#include <stdio.h>

int main(int argc, char const *argv[])
{
    int m, n, numbers[100][100], i, j;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &numbers[i][j]);

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < m; i++)
            printf("%d ", numbers[i][j]);
        printf("\n");
    }
    return 0;
}
