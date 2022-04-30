#include <stdio.h>
#include <math.h>
#include <limits.h>

int pegarLarguraNumero(int numero)
{
    int i;
    for (i = 1; i < INT_MAX; i++)
        if (numero < pow(10, i))
            return i;
}

int somaVerificadora(int matricula)
{
    int larguraNumero, soma = 0, i;

    larguraNumero = pegarLarguraNumero(matricula);

    for (i = 2; i <= larguraNumero + 1; i++)
        soma += ((((matricula % (int)pow(10, i - 1)) - (matricula % (int)pow(10, i - 2))) / (int)pow(10, i - 2)) * i);

    return soma;
}

int main()
{
    int matricula, soma, resultado;

    scanf("%d", &matricula);

    soma = somaVerificadora(matricula);

    resultado = 11 - (soma % 11);

    if (resultado <= 1)
        printf("0");
    else
        printf("%d", resultado);

    return 0;
}
