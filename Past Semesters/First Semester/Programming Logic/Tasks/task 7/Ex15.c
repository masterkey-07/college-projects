#include <stdio.h>
#include <stdlib.h>
int main()

{
    int i;
    double price;
    int quantity[40];
    double prices[40];
    double total = 0;

    for (i = 0; i < 40; i++)
        scanf("%d ", &quantity[i]);

    for (i = 0; i < 40; i++)
        scanf("%lf ", &prices[i]);

    for (i = 0; i < 40; i++)
        total += (((double)quantity[i]) * prices[i]);

    printf("%lf", total);

    return 0;
}
