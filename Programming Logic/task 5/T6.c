#include <stdio.h>
#include <stdlib.h>

int main()
{

    int resposta;

    printf("mamifero?\n");
    scanf("%d", &resposta);

    if (resposta == 1)
    {
        resposta = 0;

        printf("quadrupede?\n");
        scanf("%d", &resposta);

        if (resposta == 1)

        {
            resposta = 0;
            printf("carnivoro?\n");
            scanf("%d", &resposta);

            if (resposta == 1)
                printf("leao");
            else
            {
                resposta = 0;

                printf("herbivoro?\n");
                scanf("%d", &resposta);

                if (resposta == 1)

                    printf("cavalo");
                else
                    printf("nao sei");
            }
        }
        else
        {
            resposta = 0;

            printf("bipede?\n");
            scanf("%d", &resposta);

            if (resposta == 1)

            {
                resposta = 0;

                printf("onivoro?\n");
                scanf("%d", &resposta);

                if (resposta == 1)

                    printf("homem");
                else
                {
                    resposta = 0;

                    printf("frutifero?\n");
                    scanf("%d", &resposta);

                    if (resposta == 1)

                        printf("macaco");
                    else
                        printf("nao sei");
                }
            }
            else
            {
                resposta = 0;
                printf("voador?\n");
                scanf("%d", &resposta);

                if (resposta == 1)

                    printf("morcego");
                else
                {
                    resposta = 0;
                    printf("aquatico?\n");
                    scanf("%d", &resposta);

                    if (resposta == 1)

                        printf("baleia");
                    else
                        printf("nao sei");
                }
            }
        }
    }
    else
    {
        resposta = 0;

        printf("ave?\n");
        scanf("%d", &resposta);

        if (resposta == 1)

        {
            resposta = 0;
            printf("nao-voador?\n");
            scanf("%d", &resposta);

            if (resposta == 1)

            {
                resposta = 0;
                printf("tropical?\n");
                scanf("%d", &resposta);

                if (resposta == 1)

                    printf("avestruz");
                else
                {
                    resposta = 0;

                    printf("polar?\n");
                    scanf("%d", &resposta);

                    if (resposta == 1)

                        printf("pinguim");
                    else
                        printf("nao sei");
                }
            }
            else
            {
                resposta = 0;
                printf("nadador?\n");
                scanf("%d", &resposta);

                if (resposta == 1)

                    printf("pato");
                else
                {
                    resposta = 0;

                    printf("rapina?\n");
                    scanf("%d", &resposta);

                    if (resposta == 1)

                        printf("aguia");
                    else
                        printf("nao sei");
                }
            }
        }
        else
        {
            resposta = 0;

            printf("reptil?\n");
            scanf("%d", &resposta);

            if (resposta == 1)
            {
                resposta = 0;
                printf("com-casco?\n");
                scanf("%d", &resposta);

                if (resposta == 1)
                    printf("tartaruga");
                else
                {
                    resposta = 0;
                    printf("carnivoro?\n");
                    scanf("%d", &resposta);
                    if (resposta == 1)
                        printf("crocodilo");
                    else
                    {
                        resposta = 0;

                        printf("sem-patas?\n");
                        scanf("%d", &resposta);

                        if (resposta == 1)

                            printf("cobra");
                        else
                            printf("nao sei");
                    }
                }
            }
            else
                printf("nao sei");
        }
    }
    return 0;
}