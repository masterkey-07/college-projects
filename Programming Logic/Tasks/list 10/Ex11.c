#include <stdio.h>

int readInt()
{
    int n;

    scanf("%d", &n);

    return n;
}

int sum(int n, int *N)
{
    if (n == 1)
        return N[0];
    else
        return N[n - 1] + sum(n - 1, N);
}

int main()
{
    int n = readInt(), i;

    int N[n];

    for (i = 0; i < n; i++)
        N[i] = readInt();

    printf("%d", sum(n, N));

    return 0;
}
