#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float number;

    scanf("%f", &number);

    if (number > 0)
        printf("%f", sqrt(number));
    else
        printf("%f", pow(number, 2));

    return 0;
}
