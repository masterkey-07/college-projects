
#include <stdio.h>
#include <stdlib.h>
int main()

{
    int quantity, i, j;
    double chave;

    scanf("%d", &quantity);
    double numbers[quantity];

    for (i = 0; i < quantity; i++)
    {

        scanf("%lf ", &numbers[i]);
    }

    scanf("%lf", &chave);
    for (i = 0; i < quantity; i++)
    {
        if (chave == numbers[i])
        {
            printf("%d", i);
            break;
        }
        else if (i == quantity - 1)
        {
            printf("a chave nao foi encontrada");
        }
    }
    return 0;
}
