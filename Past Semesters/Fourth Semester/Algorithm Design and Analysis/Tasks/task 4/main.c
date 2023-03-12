#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int two_power_of(int number)
{
    return (int)pow((double)2, (double)number);
}

int solve_upper(int value)
{
    int powerup = (int)ceil(log2(value));

    int poweredup = two_power_of(powerup);

    return abs(poweredup - value);
}

int solve_lower(int value)
{
    int powerdown = (int)round(log2(value));

    int powereddown = two_power_of(powerdown);

    return abs(powereddown - value);
}

int main(int argc, char const *argv[])
{
    int value;

    scanf("%d", &value);

    int result = 0;
    int upper_solution;
    int lower_solution;

    while (value > 0)
    {
        upper_solution = solve_upper(value);

        lower_solution = solve_lower(value);

        value = upper_solution > lower_solution ? lower_solution : upper_solution;

        result++;
    }

    printf("%d", result);

    return 0;
}
