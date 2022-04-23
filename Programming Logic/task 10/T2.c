#include <stdio.h>
#include <limits.h>

int readInt()
{
    int integer;

    scanf("%d", &integer);

    return integer;
}

int isHigher(int A, int B)
{
    if (A > B)
        return 1;
    else
        return 0;
}

int isLower(int A, int B)
{
    if (A < B)
        return 1;
    else
        return 0;
}

int getMinMax(int lines, int columns, int numbers[100][100], int *minMaxLine, int *minMaxColumn)
{
    int i, j, min = INT_MAX, max = INT_MIN;

    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++)
            if (isLower(numbers[i][j], min))
            {
                min = numbers[i][j];
                *minMaxLine = i;
            }

    for (i = 0; i < columns; i++)
        if (isHigher(numbers[*minMaxLine][i], max))
        {
            max = numbers[*minMaxLine][i];
            *minMaxColumn = i;
        }

    return max;
}

int main()
{
    int lines = readInt();
    int columns = readInt();
    int i, j, numbers[100][100];
    int minMaxLine = 0, minMaxColumn = 0;
    int minMax;

    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++)
            numbers[i][j] = readInt();

    minMax = getMinMax(lines, columns, numbers, &minMaxLine, &minMaxColumn);

    printf("%d %d %d", minMaxLine, minMaxColumn, minMax);

    return 0;
}