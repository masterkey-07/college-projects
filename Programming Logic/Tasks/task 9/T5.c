#include <stdio.h>

int readInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

int compareMax(int numberA, int numberB)
{
    if (numberA >= numberB)
        return numberA;
    else
        return numberB;
}

int compareMin(int numberA, int numberB)
{
    if (numberA <= numberB)
        return numberA;
    else
        return numberB;
}

int getMinMax(int N, int M, int numbers[100][100])
{
    int i, j, max, min, minI;

    min = numbers[0][0];
    minI = 0;

    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (compareMin(min, numbers[i][j]) != min)
            {
                min = numbers[i][j];
                minI = i;
            }

    max = numbers[minI][0];

    for (i = 0; i < N; i++)
        max = compareMax(max, numbers[minI][i]);
    return max;
}

int main()
{
    int N, M, numbers[100][100], i, j, result;

    M = readInt();
    N = readInt();

    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            numbers[i][j] = readInt();

    result = getMinMax(N, M, numbers);

    printf("%d", result);
    return 0;
}
