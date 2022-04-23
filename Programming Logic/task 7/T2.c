#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, i, j, counter;

    double numeros[100], number2;

    scanf("%d", &number);

    for (i = 0; i < number; i++)
        scanf("%lf", &numeros[i]);

    for (i = 0; i < number; i++)
    {
        counter = 0;
        number2 = numeros[i];
        for (j = 0; j < number; j++)
            if (number2 == numeros[j])
                if (j >= i)
                    counter++;
                else
                    break;

        if (counter == 1)
            printf("%lf ocorre %d vez\n", number2, counter);
        else if (counter > 1)
            printf("%lf ocorre %d vezes\n", number2, counter);
    }

    return 0;
}