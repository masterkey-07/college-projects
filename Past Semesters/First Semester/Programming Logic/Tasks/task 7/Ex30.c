#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, count;

    double number, numbers[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%lf", &numbers[i]);

    for (i = 0; i < n; i++)
    {
        count = 0;
        number = numbers[i];
        for (j = 0; j < n; j++)
            if (number == numbers[j])
                if (j >= i)
                    count++;
                else
                    break;

        if (count == 1)
            printf("%lf ocorre %d vez\n", number, count);
        else if (count > 0)
            printf("%lf ocorre %d vezes\n", number, count);
    }

    return 0;
}