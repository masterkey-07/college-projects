#include <stdio.h>
#include <stdlib.h>

//DesafioFutebol
int main()
{
    //variavel
    int contador, maiorGolFeito, maiorGolTomado,
        totGolFeito, totGolTomado, numeroGolFeito, numeroGolTomado,
        saldo, quantPartida;

    double quantVitoria, quantDerrota, porcPartidas,
        porcVitorias, porcEmpates, porcDerrotas, quantEmpates,
        quantPartidasAna;

    maiorGolFeito = 0;
    totGolTomado = 0;
    totGolFeito = 0;
    quantDerrota = 0;
    quantVitoria = 0;
    maiorGolTomado = 0;

    //logica

    scanf("%d\n", &quantPartida);

    for (contador = 1; contador <= quantPartida; contador++)
    {
        scanf("%d", &numeroGolFeito);

        if (numeroGolFeito == (-1))
        {
            contador = quantPartida + 2;
        }
        else
        {
            scanf("%d", &numeroGolTomado);
            totGolFeito = totGolFeito + numeroGolFeito;
            totGolTomado = totGolTomado + numeroGolTomado;
            saldo = totGolFeito - totGolTomado;

            if (numeroGolFeito > numeroGolTomado)
            {
                quantVitoria = quantVitoria + 1;
                if (maiorGolFeito < numeroGolFeito)
                {
                    maiorGolFeito = numeroGolFeito;
                }
            }
            else
            {
                if (numeroGolTomado > numeroGolFeito)
                {

                    quantDerrota = quantDerrota + 1;
                    if (maiorGolTomado < numeroGolTomado)
                    {
                        maiorGolTomado = numeroGolTomado;
                    }
                }
                else
                {
                    quantEmpates = quantEmpates + 1;
                }
            }
        }
    }

    quantPartidasAna = quantVitoria + quantDerrota + quantEmpates;
    porcPartidas = ((quantPartidasAna)*100.0) / quantPartida;
    porcVitorias = (quantVitoria / quantPartidasAna) * 100;
    porcEmpates = ((quantEmpates / quantPartidasAna) * 100);
    porcDerrotas = (quantDerrota / quantPartidasAna) * 100;

    printf("%lf\n", porcPartidas);
    printf("%lf\n", quantVitoria * 100.0 / quantPartidasAna);
    printf("%lf\n", quantEmpates * 100.0 / quantPartidasAna);
    printf("%lf\n", quantDerrota * 100.0 / quantPartidasAna);
    printf("%d\n", totGolFeito - totGolTomado);

    if (quantDerrota != 0)
    {
        printf("%d\n", maiorGolTomado);
    }
    else
    {
        printf("Nao houve derrotas.\n");
    }

    if (quantVitoria == 0)
    {
        printf("Nao houve vitorias.");
    }
    else
    {
        printf("%d\n", maiorGolFeito);
    }
    return 0;
}