#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    int local_length, previoues_local_length = -1, start = 0, output = 0, choice;

    int another_choice, division;

    while (1)
    {
        choice = lower;

        for (i = start + 1; i < number_houses; i++)
        {
            local_length = houses[i] - houses[start];

            if (local_length > bigger && local_length > lower)
            {
                if (previoues_local_length == -1)
                    previoues_local_length = local_length;

                start = i;
                break;
            }

            if (local_length <= bigger)
                choice = bigger;

            if (local_length <= lower)
                choice = lower;

            previoues_local_length = local_length;
        }

        if (choice == bigger)
        {
            division = previoues_local_length / lower;
            another_choice = lower * (division % 2 == 0 ? division : (floor(division) + 1));
            choice = another_choice > choice ? choice : another_choice;
        }

        output += choice;

        if (i == number_houses)
            break;
    }

    printf("%d", output);

    return 0;
}
