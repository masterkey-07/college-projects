#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1026
#define MAX_HEIGHT 1026

int MIN(int a, int b)
{
    return a > b ? b : a;
}

int MAX(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    int agglomeration[MAX_WIDTH][MAX_HEIGHT]; // line - position and how many users; column - position(x, y) and users
    int square_size;                          // square's size; 1<=d<=50
    int number_positions;                     // numbers of position; 1<=n<=25000
    int x, y;                                 // quarter's position (x, y)
    int max_limit_x, max_limit_y;             // limit of square; ydt -> y top; ydi -> y bottom
    int min_limit_x, min_limit_y;             // limit of square; ydt -> y top; ydi -> y bottom
    int quantity_users;                       // quantity of users
    int i;                                    // for's variable
    int j;                                    // for's variable
    int k;                                    // for's variable
    int max_agglomeration = 0;                // max value

    for (j = 0; j < 1026; j++)
        for (k = 0; k < 1026; k++)
            agglomeration[j][k] = 0;

    scanf("%i %i", &square_size, &number_positions); // input

    // input to poits with x, y and i
    for (i = 0; i < number_positions; i++)
    {
        scanf("%i %i %i", &x, &y, &quantity_users);

        max_limit_x = MIN(x + square_size + 1, 1025);
        min_limit_x = MAX(x - square_size, 0);

        for (j = min_limit_x; j < max_limit_x; j++) // areas possíve que a grarita cobrirá esse conjunto de pessoas
        {
            max_limit_y = MIN(y + square_size + 1, 1025);
            min_limit_y = MAX(y - square_size, 0);

            for (k = min_limit_y; k < max_limit_y; k++)
            {
                if (agglomeration[j][k] > 0)
                    agglomeration[j][k] = agglomeration[j][k] + quantity_users;
                else
                    agglomeration[j][k] = quantity_users;

                if (agglomeration[j][k] > max_agglomeration)
                {
                    max_agglomeration = agglomeration[j][k];
                }
            }
        }
    }

    j = 1;
    k = 1;

    while (agglomeration[j][k] != max_agglomeration)
    {
        k++;
        if (k == 1026)
        {
            k = 0;
            j++;
        }
    }

    printf("%i %i %i", j, k, max_agglomeration);

    return 0;
}
