#include <stdio.h>

int main()
{
    // O programa funciona corretamente para todo valor Par para a variavel N
    int i, j, k, N = 6;
    for (i = 0; i < N; i++)
    {
        k = 1;
        if (i < N / 2)
            for (j = 0; j < N; j++)
            {
                if (j < N / 2 && k < i + 1 && j != 0)
                    k++;
                else if (j > (N / 2) - 1 && k > 1 && j >= N - i)
                    k--;

                printf("%d ", k);
            }
        else
            for (j = 0; j < N; j++)
            {
                if (j < N / 2 && k < (N - (i + 1)) + 1 && j != 0)
                    k++;
                else if (j > (N / 2) - 1 && k > 1 && j >= (i + 1))
                    k--;

                printf("%d ", k);
            }

        printf("\n");
    }

    return 0;
}