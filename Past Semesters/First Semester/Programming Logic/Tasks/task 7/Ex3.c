A)
#include <stdio.h>

int main()
{
    int vetor[100], i;

    for (i = 0; i < 100; i++)
        vetor[i] = 30;

    return 0;
}*/

B)
#include <stdio.h>

int main()
{
    int vetor[100], i;

    for (i = 0; i < 100; i++)
        vetor[i] = i + 1;

    return 0;
}

C)
#include <stdio.h>
#include <math.h>

    int main()
{
    int vetor[100];
    double q, j, i;

    for (j = 0; j < 100.0; j++)
    {
        q = sqrt(j);

        for (i = 1; i <= q; i++)
            if (q == i)
                vetor[(int)j] = 1;
            else if (q < i)
                break;
    }

    return 0;
}