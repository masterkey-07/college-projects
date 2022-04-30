#include <stdio.h>
#include <stdlib.h>
int main()
{

    int valor, resultado, a, b, i;
    resultado = 1;

    a = 1;

    b = 0;

    scanf("%d", &valor);

    for (i = 1; i <= valor - 1; i++)
    {
        resultado = a + b;
        b = a;
        a = resultado;
    }

    printf("%d", resultado);
}