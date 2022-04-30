#include <stdio.h>

int main()
{
    int n, numbersA[101], numbersB[101], numbersC[101], i, count = 0;

    scanf("%d", &n);

    for (i = n - 1; i >= 0; i--)
        scanf("%d", &numbersA[i]);

    for (i = n - 1; i >= 0; i--)
        scanf("%d", &numbersB[i]);

    for (i = 0; i <= n; i++)
    {
        if (i == n && count == 1)
            numbersC[i] = 1;
        else if (i == n)
            break;
        else if (numbersA[i] + numbersB[i] > 9)
        {
            numbersC[i] = numbersA[i] + numbersB[i] - 10 + count;
            count = 1;
        }
        else
        {
            numbersC[i] = numbersA[i] + numbersB[i] + count;
            count = 0;
        }
    }

    for (i = n + count - 1; i >= 0; i--)
        printf("%d", numbersC[i]);

    return 0;
}
