#include <stdio.h>
#include <limits.h>

int readInt()
{
    int integer;

    scanf("%d", &integer);

    return integer;
}

int getHighestNumber(int A, int B)
{
    if (A > B)
        return A;
    else
        return B;
}

int getLowestNumber(int A, int B)
{
    if (A < B)
        return A;
    else
        return B;
}

void getMinAndMax(int N, int numbers[], int *min, int *max)
{
    int i;

    for (i = 0; i < N; i++)
    {
        *min = getLowestNumber(*min, numbers[i]);
        *max = getHighestNumber(*max, numbers[i]);
    }
}

int main()
{
    int N = readInt();
    int numbers[100], i, min = INT_MAX, max = INT_MIN;

    for (i = 0; i < N; i++)
        numbers[i] = readInt();

    getMinAndMax(N, numbers, &min, &max);

    printf("%d %d", min, max);

    return 0;
}
