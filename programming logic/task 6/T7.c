#include <stdio.h>
#include <stdlib.h>

//DesafioTelespectadores
int main()
{
    //variavel
    int contador, globotv, sbttv, recordtv, bandeirantestv,
        culturatv, ncanal, quantPessoa;

    float totPessoas;

    contador = 1;
    ncanal = 0;
    quantPessoa = 0;
    totPessoas = 0;
    culturatv = 0;
    bandeirantestv = 0;
    recordtv = 0;
    sbttv = 0;
    globotv = 0;

    //logica
    while (contador == 1)
    {
        scanf("%d", &ncanal);
        scanf("%d", &quantPessoa);

        if (ncanal == 17)
            globotv = globotv + quantPessoa;
        if (ncanal == 18)
            sbttv = sbttv + quantPessoa;
        if (ncanal == 19)
            recordtv = recordtv + quantPessoa;
        if (ncanal == 20)
            bandeirantestv = bandeirantestv + quantPessoa;
        if (ncanal == 22)
            culturatv = culturatv + quantPessoa;
        if ((ncanal != 17) && (ncanal != 18) && (ncanal != 19) && (ncanal != 20) && (ncanal != 22))
            contador = 0;
    }

    totPessoas = globotv + sbttv + recordtv + bandeirantestv + culturatv;

    if (globotv != 0)
        printf("%d %f\n", 17, (globotv * 100.0) / totPessoas);

    if (sbttv != 0)
        printf("%d %f\n", 18, (sbttv * 100.0) / totPessoas);

    if (recordtv != 0)
        printf("%d %f\n", 19, (recordtv * 100.0) / totPessoas);

    if (bandeirantestv != 0)
        printf("%d %f\n", 20, (bandeirantestv * 100.0) / totPessoas);

    if (culturatv != 0)
        printf("%d %f\n", 22, (culturatv * 100.0) / totPessoas);
}