#include <stdio.h>
#define line 1026
#define colum 1026

int main(int argc, char const *argv[])
{
    int agglomeration[line][colum]; // line - position and how many users; colum - position(x, y) and users
    int square_size;                // square's size; 1<=d<=50
    int number_positions;           // numbers of position; 1<=n<=25000
    int x, y;                       // quarter's position (x, y)
    int limit_x, limit_y;           // limit of square; ydt -> y top; ydi -> y bottom
    int quantity_users;             // quantity of users
    int i;                          // for's variable
    int j;                          // for's variable
    int k;                          // for's variable
    int max = 0;                    // max value

    for (j = 0; j < 1026; j++)
        for (k = 0; k < 1026; k++)
            agglomeration[j][k] = 0;

    scanf("%i %i", &square_size, &number_positions); // input

    // input to poits with x, y and i
    for (i = 0; i < number_positions; i++)
    {
        scanf("%i %i %i", &x, &y, &quantity_users);

        limit_x = x + square_size + 1;

        for (j = x - square_size; j < limit_x; j++)
            if (j > -1 && j < 1026)
            {
                limit_y = y + square_size + 1;

                for (k = y - square_size; k < limit_y; k++)
                    if (k > -1 && k < 1026)
                    {
                        if (agglomeration[j][k] > 0)
                            agglomeration[j][k] = agglomeration[j][k] + quantity_users;
                        else
                            agglomeration[j][k] = quantity_users;

                        if (agglomeration[j][k] > max)
                            max = agglomeration[j][k];
                    }
            }
    }

    j = 1;
    k = 1;

    while (agglomeration[j][k] != max)
    {
        k++;
        if (k == 1026)
        {
            k = 0;
            j++;
        }
    }

    printf("%i %i %i", j, k, max);

    return 0;
}