#include <stdio.h>
#include <limits.h>

int main()
{
    int n, numbersA[100], numbersB[100], numbersC[100], i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &numbersA[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &numbersB[i]);

    for (i = 0; i < n; i++)
        numbersC[i] = numbersA[i] * numbersB[i];

    for (i = 0; i < n; i++)
        printf("%d ", numbersC[i]);
    return 0;
}
