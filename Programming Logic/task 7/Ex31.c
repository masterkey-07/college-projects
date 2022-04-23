#include <stdio.h>
#include <limits.h>
int main()
{
    int n, numbers[50], i, j, a, b, x = INT_MIN, y = INT_MIN, m;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    for (i = 0; i < n - 1; i++)
    {
        a = numbers[i];
        b = numbers[i + 1];

        for (j = i + 2; j < n - 1; j++)
        {
            if (a == numbers[j] && b == numbers[j + 1])
            {
                x = i;
                y = j;
            }
        }
    }

    m = y - x;

    if (x != INT_MIN)
        printf("%d %d", x + 1, m);

    return 0;
}
