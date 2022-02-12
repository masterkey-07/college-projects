#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ganhoMensal, ganhoMensalMulta;

    int numeroFitas, valorFita, numeroFitasPerdidas, numeroFinalFitas;

    scanf("%d %d", &numeroFitas, &valorFita);

    ganhoMensal = ((numeroFitas / 3.0) * valorFita);

    ganhoMensalMulta = ((numeroFitas / 3 / 10) * 0.1 * valorFita);

    numeroFitasPerdidas = numeroFitas * 0.02;

    numeroFinalFitas = numeroFitas - numeroFitasPerdidas + (numeroFitasPerdidas * 0.1);

    printf("%f\n", ganhoMensal);

    printf("%f\n", ganhoMensalMulta);

    printf("%d\n", numeroFinalFitas);

    return 0;
}