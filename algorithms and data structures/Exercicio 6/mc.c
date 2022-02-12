#include <stdio.h>
#include <string.h>
#include <math.h>

/* Informações 
    - Maria Clara Almeida Galvao
    - RA: 156.592
    -Turma: Noturno NB */

typedef struct listaEnc
{
    int coef;
    int grau;
    struct listaEnc *ant;
    struct listaEnc *prox;
} lista;
typedef lista *Plista;

int libera_lista(Plista p)
{
    if (p != NULL)
    {
        libera_lista(p->prox);
        free(p);
    }
    return NULL;
}

Plista buscar_lista(Plista l, int val)
{
    Plista p;
    for (p = l; p != NULL; p = p->prox)
        if (p->coef == val)
            return p;
    return NULL;
}

Plista retirar_coef_0(Plista l, int zero)
{
    Plista p = buscar_lista(l, zero);
    if (p == NULL)
        return l;

    if (l == p)
        l = p->prox;
    else
        p->ant->prox = p->prox;

    if (p->prox != NULL)
        p->prox->ant = p->ant;

    return l;
}

Plista insere_ordenado(Plista l, int coef, int grau)
{
    Plista nova_lista = (Plista)malloc(sizeof(lista));
    nova_lista->coef = coef;
    nova_lista->grau = grau;
    nova_lista->ant = NULL;
    nova_lista->prox = NULL;

    if (l == NULL)
        return nova_lista;

    Plista list = l;

    do
    {
        if (list->grau < grau)
        {
            if (list->ant == NULL)
            {
                nova_lista->prox = list;
                l = nova_lista;
                break;
            }

            nova_lista->ant = list->ant;
            nova_lista->prox = list;
            list->ant = nova_lista;
            list = nova_lista->ant;
            list->prox = nova_lista;

            break;
        }
        else if (list->grau == grau)
        {
            list->coef += coef;

            break;
        }
        else if (list->grau > grau)
        {
            if (list->prox == NULL)
            {
                nova_lista->ant = list;
                list->prox = nova_lista;
                break;
            }
        }

        list = list->prox;
    } while (list != NULL);

    return l;
}

Plista insere(Plista l, int coef, int grau)
{
    Plista novo = (Plista)malloc(sizeof(lista));
    novo->coef = coef;
    novo->grau = grau;
    novo->prox = l;
    novo->ant = NULL;
    if (l != NULL)
        l->ant = novo;
    return novo;
}

void imprime_lista(Plista l)
{
    while (l)
    {
        if (l->coef > 0)
            printf("+%dx^%d ", l->coef, l->grau);
        else
            printf("%dx^%d ", l->coef, l->grau);

        l = l->prox;
    }
}

Plista diminuir_polinomios(Plista l, Plista m)
{
    Plista diferenca = NULL, i, j;
    int semelhante = 0;

    for (i = l; i != NULL; i = i->prox)
    {
        semelhante = 0;
        for (j = m; j != NULL; j = j->prox)
        {
            if (i->grau == j->grau)
            {
                diferenca = insere_ordenado(diferenca, i->coef - j->coef, i->grau);
                semelhante = 1;
                break;
            }
        }

        if (semelhante == 0)
            diferenca = insere_ordenado(diferenca, i->coef, i->grau);
    }

    for (j = m; j != NULL; j = j->prox)
    {
        semelhante = 0;
        for (i = l; i != NULL; i = i->prox)
        {
            if (i->grau == j->grau)
            {
                semelhante = 1;
                break;
            }
        }

        if (semelhante == 0)
            diferenca = insere_ordenado(diferenca, j->coef, j->grau);
    }

    return diferenca;
}

Plista somar_polinomio(Plista l, Plista m)
{
    Plista soma = NULL, i, j;
    int semelhante = 0;

    for (i = l; i != NULL; i = i->prox)
    {
        semelhante = 0;
        for (j = m; j != NULL; j = j->prox)
        {
            if (i->grau == j->grau)
            {
                soma = insere_ordenado(soma, i->coef + j->coef, i->grau);
                semelhante = 1;
                break;
            }
        }

        if (semelhante == 0)
            soma = insere_ordenado(soma, i->coef, i->grau);
    }

    for (j = m; j != NULL; j = j->prox)
    {
        semelhante = 0;
        for (i = l; i != NULL; i = i->prox)
        {
            if (i->grau == j->grau)
            {
                semelhante = 1;
                break;
            }
        }

        if (semelhante == 0)
            soma = insere_ordenado(soma, j->coef, j->grau);
    }

    return soma;
}

int proibir_grau_0(Plista l)
{
    int maior_grau, sinal = 0;
    Plista i;
    for (i = l; i != NULL; i = i->prox)
    {
        maior_grau = i->grau;
        if (maior_grau > 0)
            sinal = 1;
    }
    return sinal;
}

Plista derivada_polinomios(Plista l)
{
    Plista lista_derivada = NULL;
    while (l)
    {
        lista_derivada = insere_ordenado(lista_derivada, l->coef * l->grau, l->grau - 1);
        l = l->prox;
    }

    return retirar_coef_0(lista_derivada, 0);
}

int main()
{
    int coef, grau, i, j, k, l = 0, opcao, soma, sinal = 1, vdd_falso = 1, loop = 1, verif_grau;
    char vetor[99];
    Plista lista1 = NULL;
    Plista lista2 = NULL;
    Plista soma_lista = NULL;
    Plista diferenca_lista = NULL;
    Plista lista_derivada = NULL;

    while (loop == 1)
    {
        printf("Selecione uma opcao: \n");
        printf("1) Inserir novos polinomios\n2) Somar polinomios\n3) Subtrair polinomios\n4) Derivar um polinomio\n5) Sair\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            libera_lista(lista1);
            libera_lista(lista2);
            lista1 = NULL;
            lista2 = NULL;

            while (l != 2)
            {
                fflush(stdin);
                scanf("%[^\n]%*c", vetor);

                for (i = 0; i < strlen(vetor); i++)
                {
                    if (vetor[i] >= 48 && vetor[i] <= 57)
                    {
                        for (j = i + 1; vetor[j] >= 48 && vetor[j] <= 57; j++)
                        {
                        }
                        j--;
                        soma = 0;
                        for (k = i; k <= j; k++)
                        {
                            soma += (vetor[k] - 48) * pow(10, j - k);
                        }
                        soma = sinal * soma;
                        sinal = 1;
                        i = j;
                        if (vdd_falso == 1)
                        {
                            coef = soma;
                            vdd_falso = 0;
                        }
                        else
                        {
                            grau = soma;
                            vdd_falso = 1;
                            if (l == 1)
                            {
                                lista2 = insere_ordenado(lista2, coef, grau);
                                lista2 = retirar_coef_0(lista2, 0);
                                verif_grau = proibir_grau_0(lista2);
                                if (verif_grau == 0)
                                {
                                    printf("Erro! Maior grau eh zero.");
                                    return 0;
                                }
                            }
                            else
                            {
                                lista1 = insere_ordenado(lista1, coef, grau);
                                lista1 = retirar_coef_0(lista1, 0);
                                verif_grau = proibir_grau_0(lista1);

                                if (verif_grau == 0)
                                {
                                    printf("Erro! Maior grau eh zero.");
                                    return 0;
                                }
                            }
                        }
                    }
                }
                l++;
            }
            imprime_lista(lista1);
            printf("\n");
            break;
        case 2:
            soma_lista = somar_polinomio(lista1, lista2);
            soma_lista = retirar_coef_0(soma_lista, 0);
            imprime_lista(soma_lista);
            printf("\n");
            break;
        case 3:
            diferenca_lista = diminuir_polinomios(lista1, lista2);
            diferenca_lista = retirar_coef_0(diferenca_lista, 0);
            imprime_lista(diferenca_lista);
            printf("\n");
            break;
        case 4:
            printf("Selecione o polinomio a derivar (1-primeiro, 2-segundo):");
            scanf("%d", &opcao);
            if (opcao == 1)
            {
                lista_derivada = derivada_polinomios(lista1);
                lista_derivada = retirar_coef_0(lista_derivada, 0);
                imprime_lista(lista_derivada);
            }
            else
            {
                lista_derivada = derivada_polinomios(lista2);
                lista_derivada = retirar_coef_0(lista_derivada, 0);
                imprime_lista(lista_derivada);
            }
            break;
        case 5:
            libera_lista(lista1);
            libera_lista(lista2);
            libera_lista(soma_lista);
            libera_lista(diferenca_lista);
            libera_lista(lista_derivada);
            free(vetor);
            loop = 0;
            break;
        }
    }

    return 0;
}