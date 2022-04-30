#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, numbers[100][100], i, j, result = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &numbers[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (numbers[i][j] != numbers[j][i])
            {
                result = 0;
                break;
            }

    printf("%d", result);
    return 0;
}
