#include <stdio.h>

int readInt()
{
    int integer;

    scanf("%d", &integer);

    return integer;
}

int includes(int group[100], int size, int number)
{
    int i;
    for (i = 0; i < size; i++)
        if (group[i] == number)
            return 1;

    return 0;
}

void doUnion(int M, int A[100], int N, int B[100], int *P, int C[200])
{
    int i, sum = 0;

    for (i = 0; i < M; i++)
        if (includes(B, N, A[i]))
            if (!includes(C, *P, A[i]))
                C[(*P)++] = A[i];
}

int getSum(int P, int C[200])
{
    int sum = 0, i;

    for (i = 0; i < P; i++)
        sum += C[i];

    return sum;
}

int main()
{

    int A[100], B[100], C[200], p, i, result;

    int numberA = readInt();

    for (i = 0; i < numberA; i++)
        A[i] = readInt();

    int numberB = readInt();

    for (i = 0; i < numberB; i++)
        B[i] = readInt();

    p = 0;

    doUnion(numberA, A, numberB, B, &p, C);

    result = getSum(p, C);

    printf("%d", result);

    return 0;
}
