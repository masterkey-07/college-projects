#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int merge(int *houses, int start, int end, int lower, int bigger)
{

    int local_length, output = 0, choice, i;

    int number_houses = end + 1;

    while (1)
    {
        choice = lower;

        for (i = start + 1; i < number_houses; i++)
        {
            local_length = houses[i] - houses[start];

            if (local_length > bigger && local_length > lower)
            {
                start = i;
                break;
            }

            if (local_length <= bigger)
                choice = bigger;

            if (local_length <= lower)
                choice = lower;
        }

        output += choice;

        if (i == number_houses)
            break;
    }

    return output;
}

int inverse_merge(int *houses, int start, int end, int lower, int bigger)
{

    int local_length, output = 0, choice, i;

    while (1)
    {
        choice = lower;

        for (i = end - 1; i >= start; i--)
        {
            local_length = houses[end] - houses[i];

            if (local_length > bigger && local_length > lower)
            {
                end = i;
                break;
            }

            if (local_length <= bigger)
                choice = bigger;

            if (local_length <= lower)
                choice = lower;
        }

        output += choice;

        if (i == start - 1)
            break;
    }

    return output;
}

int solution(int *houses, int start, int end, int lower, int bigger)
{
    if (start == end)
        return lower;

    int half = (start + end) / 2;

    int asnwer_a = solution(houses, start, half, lower, bigger);
    int asnwer_b = solution(houses, half + 1, end, lower, bigger);

    int asnwer_c = merge(houses, start, end, lower, bigger);

    return asnwer_a + asnwer_b > asnwer_c ? asnwer_c : asnwer_a + asnwer_b;
}

int main(int argc, char const *argv[])
{
    int antennas[2];

    int number_houses, street_length;

    scanf("%d", &number_houses);
    scanf("%d", &street_length);
    scanf("%d", &antennas[0]);
    scanf("%d", &antennas[1]);

    int bigger = antennas[0] > antennas[1] ? antennas[0] : antennas[1];

    int lower = antennas[1] > antennas[0] ? antennas[0] : antennas[1];

    int *houses = (int *)malloc(sizeof(int) * number_houses);

    int i;

    for (i = 0; i < number_houses; i++)
        scanf("%d", &houses[i]);

    int output = solution(houses, 0, number_houses - 1, lower, bigger);

    printf("%d", output);

    return 0;
}
