#include <stdio.h>

int readInt()
{
    int n;

    scanf("%d", &n);

    return n;
}

int printInverse(int n, int numbers[n])
{
    if (n == 1)
        printf("%d ", numbers[0]);
    else
    {
        printf("%d ", numbers[n - 1]);
        printInverse(n - 1, numbers);
    }
}

int main()
{
    int n = readInt(), i;

    int N[n];

    for (i = 0; i < n; i++)
        N[i] = readInt();

    printInverse(n, N);

    return 0;
}
