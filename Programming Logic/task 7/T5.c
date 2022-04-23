#include <stdio.h>

int main()
{
    int numbers[100], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    for (i = n - 1; i >= 0; i--)
        printf("%d", numbers[i]);

    return 0;
}
