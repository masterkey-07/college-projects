#include <stdio.h>
#include <limits.h>
int main()
{
    int numbersA[65536], numbersB[65536], N, i, j, hasNumber, a, b, d, c;

    for (i = 0; i < 65536; i++)
    {
        numbersA[i] = INT_MIN;
        numbersB[i] = INT_MIN;
    }

    scanf("%d", &N);

    hasNumber = 1;

    numbersA[0] = 0;
    numbersB[0] = 1;

    numbersA[1] = 1;
    numbersB[1] = 1;

    while (hasNumber == 1)
    {
        hasNumber = 0;

        i = 0;
        while (1 == 1)
        {
            if (numbersA[i + 1] == INT_MIN)
                break;

            if (numbersB[i] + numbersB[i + 1] <= N)
            {
                a = numbersA[i + 1];
                b = numbersB[i + 1];
                numbersA[i + 1] = numbersA[i] + a;
                numbersB[i + 1] = numbersB[i] + b;
                hasNumber = 1;
                c = a;
                d = b;
                for (j = i + 2; j < 65535; j++)
                {
                    if (c == INT_MIN)
                        break;
                    a = numbersA[j];
                    b = numbersB[j];
                    numbersA[j] = c;
                    numbersB[j] = d;
                    c = a;
                    d = b;
                }
            }

            i++;
        }
    }

    for (i = 0; i < 65536; i++)
    {
        if (numbersA[i] == INT_MIN)
            break;

        printf("%d/%d\n", numbersA[i], numbersB[i]);
    }

    return 0;
}
