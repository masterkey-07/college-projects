#include <stdio.h>

int readInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

int getMatrixDeterminantOfTwo(int A[2][2])
{
    int a = A[0][0] * A[1][1];
    int b = A[0][1] * A[1][0];

    return a - b;
}

void reduceMatrix(int N, int A[N][N], int line, int column, int B[N - 1][N - 1])
{
    int x = 0, y = 0;
    int i = 0, j = 0;

    N--;

    for (i = 0; i < N + 1; i++)
    {
        y = 0;
        if (i != line)
        {
            for (j = 0; j < N + 1; j++)
                if (column != j)
                {
                    B[x][y] = A[i][j];
                    y++;
                }
            x++;
        }
    }

    return B;
}

int getMatrixDeterminant(int N, int A[N][N])
{
    int i, j, isSum = 1, result = 0, product;

    int B[N - 1][N - 1];

    if (N == 2)
        return getMatrixDeterminantOfTwo(A);

    for (i = 0; i < 1; i++)
    {
        isSum = 1;
        for (j = 0; j < N; j++)
        {
            reduceMatrix(N, A, i, j, B);

            product = A[i][j] * getMatrixDeterminant(N - 1, B);

            if (isSum == 1)
            {
                if (N == 4)
                    printf("%d += %d   [%d]\n", result, product, N);
                result += product;
                isSum = 0;
            }
            else
            {
                if (N == 4)
                    printf("%d -= %d   [%d]\n", result, product, N);
                result -= product;
                isSum = 1;
            }
        }
    }
    return result;
}

int main()
{
    int N = readInt(), i, j;

    int A[N][N];

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            A[i][j] = readInt();

    printf("%d", getMatrixDeterminant(N, A));

    return 0;
}
