#include <stdio.h>
#include <limits.h>

int main()
{
    int n, numbers[100], result = INT_MIN, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    for (i = 0; i < n; i++)
        if (numbers[i] > result)
            result = numbers[i];

    printf("%d", result);

    return 0;
}
