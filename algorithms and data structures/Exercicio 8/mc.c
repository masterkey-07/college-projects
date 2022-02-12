#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodulo
{
    void *info;
    struct Nodulo *nodulo_esquerdo;
    struct Nodulo *nodulo_direito;
    int tipo;

} TNodulo;
typedef TNodulo *PArv;

void liberar_arv(PArv arvore)
{
    if (arvore != NULL)
    {
        free(arvore->nodulo_direito);
        free(arvore->nodulo_esquerdo);
        free(arvore);
    }
}

void saida_arv(PArv num, int x)
{
    int i;
    if (num->tipo != 1)
    {
        for (i = 0; i < 1 + x; i++)
            printf("\t");
        printf("%d\n", num->nodulo_esquerdo->info);

        for (i = 0; i < x; i++)
            printf("\t");

        printf("%c\n", num->info);

        saida_arv(num->nodulo_direito, (x + 1));
    }
    else
    {
        for (i = 0; i < x; i++)
            printf("\t");

        printf("%d\n", num->info);
    }
}

int resolver_expressao(PArv arvore)
{
    int calculo;
    if (arvore->tipo == 1)
        return (arvore->info);
    else if (arvore->info == '+')
    {
        calculo = resolver_expressao(arvore->nodulo_direito) + (int)arvore->nodulo_esquerdo->info;
        return calculo;
    }
    else
    {
        calculo = resolver_expressao(arvore->nodulo_direito) - (int)arvore->nodulo_esquerdo->info;
        return calculo;
    }
}

char simbolo_verificador(char *expressao, int *posicao)
{
    int i;
    char simbolo;

    if (*posicao < 0)
        return NULL;

    for (i = *posicao; i >= 0; i--)
    {
        if (expressao[i] >= 48 && expressao[i] <= 57)
            return NULL;
        else if (expressao[i] == '-')
        {
            *posicao = i - 1;
            simbolo = '-';
            return simbolo;
        }
        else if (expressao[i] == '+')
        {
            *posicao = i - 1;
            simbolo = '+';
            return simbolo;
        }
    }
}

int isolar_numero(char *expressao, int *posicao)
{
    int i, comparar = 0, posiFinal = -1, posiInicio = 0;
    for (i = *posicao; i >= 0; i--)
    {
        comparar = 0;
        if (expressao[i] >= 48 && expressao[i] <= 57)
        {
            comparar = 1;
        }
        if (comparar == 1 && posiFinal == -1)
        {
            posiFinal = i;
        }
        else if (comparar == 0 && posiFinal != -1 && posiInicio == 0)
            posiInicio = i + 1;
    }

    if (posiFinal == -1)
        return NULL;
    else
    {
        *posicao = posiInicio - 1;
        return transformar_em_int(expressao, posiInicio, posiFinal);
    }
}

PArv arvore_montar(char *expressao, int *posicao)
{
    char simbolo;
    int numero;

    PArv arvore = (PArv)malloc(sizeof(TNodulo));

    PArv folha;

    arvore->tipo = 0;

    numero = isolar_numero(expressao, posicao);

    simbolo = simbolo_verificador(expressao, posicao);

    if (simbolo == NULL)
    {
        arvore->tipo = 1;
        arvore->info = numero;
        arvore->nodulo_esquerdo = NULL;
        arvore->nodulo_direito = NULL;

        return arvore;
    }
    else
    {
        folha = (PArv)malloc(sizeof(TNodulo));

        folha->nodulo_esquerdo = NULL;
        folha->nodulo_direito = NULL;
        folha->tipo = 1;
        folha->info = numero;

        arvore->nodulo_esquerdo = folha;

        arvore->info = simbolo;

        arvore->nodulo_direito = arvore_montar(expressao, posicao);

        return arvore;
    }
}

int transformar_em_int(char *expressao, int inicio, int fim)
{
    int i, retorno = 0, numero, unidade;

    for (i = inicio; i <= fim; i++)
    {
        numero = expressao[i] - 48;
        unidade = pow(10, fim - i);
        retorno += numero * unidade;
    }

    return retorno;
}

int verificar_expressao(char *expressao, int pos, int len, int tipo)
{
    int i;
    int eh_tipo = 0, comparar = 0;
    if (pos >= len)
        return 1;

    if (tipo == 1)
    {
        tipo = 2;
        for (i = pos; i <= len; i++)
        {
            if (expressao[i] >= 48 && expressao[i] <= 57)
                comparar = 1;
            else
                comparar = 0;

            if ((expressao[i] == '+' || expressao[i] == '-') && eh_tipo == 0)
            {
                return 0;
            }
            else if (comparar == 1)
            {
                eh_tipo = 1;
            }
            else if (comparar == 0 && eh_tipo != 0)
            {
                return verificar_expressao(expressao, i, len, tipo);
            }
        }
    }
    else
    {
        tipo = 1;
        for (i = pos; i <= len; i++)
        {
            if (expressao[i] >= 48 && expressao[i] <= 57)
                comparar = 1;
            else
                comparar = 0;

            if (comparar == 1)
            {
                return 0;
            }
            else if (expressao[i] == '+' || expressao[i] == '-')
            {
                return verificar_expressao(expressao, i + 1, len, tipo);
            }
        }
    }

    return 1;
}

int main()
{
    int aux = 0, comparar = 0, i, j, resultado, verificacao;
    char expressao[500];
    int *len = (int *)malloc(sizeof(int));

    printf("Digite a expressao:");
    scanf("%[^\n]s", expressao);

    PArv arvore = (PArv)malloc(sizeof(TNodulo));

    for (i = 0; i < 500; i++)
        if (expressao[i] == '\0')
        {
            *len = i - 1;
            i = 501;
        }

    verificacao = verificar_expressao(expressao, 0, *len, 1);

    if (verificacao == 0)
    {
        printf("expressao incorreta.");

        return 0;
    }

    arvore = arvore_montar(expressao, len);

    saida_arv(arvore, 0);

    resultado = resolver_expressao(arvore);

    printf("A solucao da expressao eh: %d", resultado);

    liberar_arv(arvore);

    free(len);
    return 0;
}