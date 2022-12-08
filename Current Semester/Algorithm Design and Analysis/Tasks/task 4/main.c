#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int value;

    scanf("%d", &value);

    int result = 0;

    int power = 0;

    int powered = 0;

    while (value > 0)
    {
        power = (int)ceil(log2(value));

        powered = (int)pow((double)2, (double)power);

        value = powered - value;

        result++;
    }

    printf("%d", result);

    return 0;
}
