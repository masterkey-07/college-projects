#include <stdio.h>

int readInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

int getInitialSum(int n, int numbers[100][100])
{
    int result = 0, i;

    for (i = 0; i < n; i++)
        result += numbers[0][i];

    return result;
}

int verifyRows(int n, int numbers[100][100], int constSum)
{
    int i, sum, j;

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum += numbers[i][j];

        if (sum != constSum)
            return 0;
    }

    return 1;
}

int verifyColumns(int n, int numbers[100][100], int constSum)
{
    int i, sum, j;
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum += numbers[i][j];

        if (sum != constSum)
            return 0;
    }

    return 1;
}

int verifyDiagonal(int n, int numbers[100][100], int constSum)
{
    int i, sum;
    for (i = 0; i < n; i++)
        sum += numbers[i][i];

    if (sum != constSum)
        return 0;

    return 1;
}

int verifySecondaryDiagonal(int n, int numbers[100][100], int constSum)
{
    int i, sum;

    for (i = 0; i < n; i++)
        sum += numbers[i][n - i - 1];

    if (sum != constSum)
        return 0;

    return 1;
}

int endProgram(int result)
{
    if (result == 0)
    {
        printf("0");
        return 1;
    }
    else
        return 0;
}

int main()
{
    int n, numbers[100][100], i, j, result = 0, sum = 0, constSum = 0;

    n = readInt();

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            numbers[i][j] = readInt();

    constSum = getInitialSum(n, numbers);

    if (endProgram(verifyRows(n, numbers, constSum)))
        return 0;

    if (endProgram(verifyColumns(n, numbers, constSum)))
        return 0;

    if (endProgram(verifyDiagonal(n, numbers, constSum)))
        return 0;

    if (endProgram(verifySecondaryDiagonal(n, numbers, constSum)))
        return 0;

    printf("%d", constSum);

    return 0;
}