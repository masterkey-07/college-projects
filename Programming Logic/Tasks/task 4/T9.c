#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numeroConta,
        valor1,
        valor2,
        valor3,
        numeroContaInvertido,
        numeroContaSomado,
        resultado;

    scanf("%d", &numeroConta);

    valor1 = numeroConta % 10;

    valor2 = ((numeroConta % 100) - (numeroConta % 10)) / 10;

    valor3 = (numeroConta - (numeroConta % 100)) / 100;

    numeroContaInvertido = (valor1 * 100) + (valor2 * 10) + valor3;

    numeroContaSomado = numeroConta + numeroContaInvertido;

    valor1 = numeroContaSomado % 10;

    valor2 = ((numeroContaSomado % 100) - (numeroContaSomado % 10)) / 10;

    valor3 = (numeroContaSomado - (numeroContaSomado % 100)) / 100;

    resultado = (valor3 * 1) + (valor2 * 2) + (valor1 * 3);

    printf("%d", resultado % 10);

    return 0;
}
