#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idadesSomadas = 0, diffOtimoRuim, numeroPessoas, maiorIdadePessimo = 0, maiorIdadeOtimo = 0, maiorIdadeRuim = 0, contador, numeroRespostasOtimas = 0, numeroRespostasBom = 0, numeroRespostasRegular = 0, numeroRespostasRuim = 0, numeroRespostasPessima = 0;

    double diffBomRegular;

    scanf("%d", &numeroPessoas);

    int entrada[numeroPessoas][2];

    for (contador = 0; contador < numeroPessoas; contador++)
    {
        scanf("%d %d", &entrada[contador][0], &entrada[contador][1]);
    }

    for (contador = 0; contador < numeroPessoas; contador++)
    {

        if (entrada[contador][1] == 5)
        {
            numeroRespostasOtimas++;

            if (maiorIdadeOtimo < entrada[contador][0])
            {
                maiorIdadeOtimo = entrada[contador][0];
            }
        }
        else if (entrada[contador][1] == 4)
        {
            numeroRespostasBom++;
        }
        else if (entrada[contador][1] == 3)
        {
            numeroRespostasRegular++;
        }
        else if (entrada[contador][1] == 2)
        {
            idadesSomadas += entrada[contador][0];
            numeroRespostasRuim++;

            if (maiorIdadeRuim < entrada[contador][0])
            {
                maiorIdadeRuim = entrada[contador][0];
            }
        }
        else if (entrada[contador][1] == 1)
        {
            numeroRespostasPessima++;
            if (maiorIdadePessimo < entrada[contador][0])
            {
                maiorIdadePessimo = entrada[contador][0];
            }
        }
    }

    printf("%d\n", numeroRespostasOtimas);

    diffBomRegular = ((((double)numeroRespostasBom) * 100.0) / numeroPessoas) - ((((double)numeroRespostasRegular) * 100.0) / numeroPessoas);

    if (diffBomRegular < 0)
    {
        diffBomRegular = -diffBomRegular;
    }

    printf("%lf\n", diffBomRegular);
    printf("%lf\n", (((double)idadesSomadas)) / numeroRespostasRuim);
    printf("%lf %d\n", (((double)numeroRespostasPessima) * 100) / numeroPessoas, maiorIdadePessimo);

    diffOtimoRuim = maiorIdadeOtimo - maiorIdadeRuim;

    if (diffOtimoRuim < 0)
    {
        diffOtimoRuim = -diffOtimoRuim;
    }

    printf("%d", diffOtimoRuim);

    return 0;
}
