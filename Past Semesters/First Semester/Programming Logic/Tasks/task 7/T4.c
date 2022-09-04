#include <stdio.h>
#include <limits.h>

int main()
{
    int enumerador, numero, numeros[100], contador, quantidade = 0;

    scanf("%d", &enumerador);

    for (contador = 0; contador < enumerador; contador++)
    {
        scanf("%d", &numeros[contador]);
    }
    scanf("%d", &numero);

    for (contador = 0; contador < enumerador; contador++)
    {
        if (numeros[contador] == numero)
        {
            quantidade = quantidade + 1;
        }
    }
    printf("%d\n", quantidade);

    for (contador = 0; contador < enumerador; contador++)
    {
        if (numeros[contador] == numero)
        {
            printf("%d\n", contador);
        }
    }
    return 0;
}
