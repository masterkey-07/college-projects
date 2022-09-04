#include <stdio.h>
#include <limits.h>
int main(int argc, char const *argv[])
{
    int m, n, i, j, number = INT_MIN, rI, rJ, asnwer;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &asnwer);
            if (asnwer > number)
            {
                rI = i;
                rJ = j;
                number = asnwer;
            }
        }

    printf("%d %d", rI, rJ);

    return 0;
}
