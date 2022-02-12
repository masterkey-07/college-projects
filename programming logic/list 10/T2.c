#include <stdio.h>

int readInt()
{
    int n;

    scanf("%d", &n);

    return n;
}

int getMax(int n, int numbers[n])
{
    int max;

    if (n == 1)
        return numbers[0];
    else
    {
        int max = getMax(n - 1, numbers);

        if (numbers[n - 1] < max)
            return max;
        else
            return numbers[n - 1];
    }
}

int main()
{
    int n = readInt(), i;

    int N[n];

    for (i = 0; i < n; i++)
        N[i] = readInt();

    printf("%d", getMax(n, N));

    return 0;
}
