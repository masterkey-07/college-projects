#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Informações 
    - Maria Clara Almeida Galvao
    - RA: 156.592
    -Turma: Noturno */

typedef struct no No;

//Struct da Lista
struct no
{
    char num;
    struct no *prox;
};

//Função para Criar nó (célula) na lista
No *criar_no()
{
    No *novo = (No *)malloc(sizeof(No));
    return novo;
}

//Inserir informação no inicio da lista
No *inserir_no_inicio(No *lista, char dado)
{
    No *novo_no = criar_no();
    novo_no->num = dado;

    if (lista == NULL)
    {
        lista = novo_no;
        novo_no->prox = NULL;
    }
    else
    {
        novo_no->prox = lista;
        lista = novo_no;
    }
    return lista;
}

//Imprimir lista
void imprimir_lista(No *lista)
{
    No *aux = lista;

    while (aux != NULL)
    {
        printf("%c", aux->num);
        aux = aux->prox;
    }
}

//Converter char para Int (para realizar soma)
int charToInt(char numero)
{
    int inteiro;

    inteiro = ((int)numero) - '0';

    return inteiro;
}

//Converter int para char (voltar ao tipo anterior de nó da lista)
char intToChar(int numero)
{
    char caractere;

    caractere = ((char)numero) + '0';

    return caractere;
}

//Pega o ultimo número de uma soma > 9
char pegarUltimoNumero(int soma)
{

    int ultimo_numero;
    char converter;

    ultimo_numero = (intToChar(soma % 10));

    return ultimo_numero;
}

//Funçao que recursiva que realiza soma
No *func_soma(No *lista1, No *lista2, No *listaR, int posA, int posB, int *aux)
{
    int soma;
    No *seq1 = lista1;
    No *seq2 = lista2;

    //Verifica se foi digitado algum numero
    if (posA == 0 && posB == 0)
    {
        return NULL;
    }
    else
    {
        //Verifica se estao com a mesma quantidade de algarismos
        if (posA == posB)
        {
            soma = charToInt(seq1->num) + charToInt(seq2->num);
            seq1 = seq1->prox;
            seq2 = seq2->prox;
            posA--;
            posB--;
            listaR = func_soma(seq1, seq2, listaR, posA, posB, aux);
            soma += *aux;
        }
        else
        {
            //Verifica se o numero 1 possui mais algarismos
            if (posA > posB)
            {
                soma = charToInt(seq1->num);
                seq1 = seq1->prox;
                posA--;
                listaR = func_soma(seq1, seq2, listaR, posA, posB, aux);
                soma += *aux;
            }
            else
            {
                //Lógica caso o numero 2 possua mais algarismos
                soma = charToInt(seq2->num);
                seq2 = seq2->prox;
                posB--;
                listaR = func_soma(seq1, seq2, listaR, posA, posB, aux);
                soma += *aux;
            }
        }
    }
    //Verifica se a soma resulta em um número igual ou maior que 10
    if (soma > 9)
    {
        *aux = 1;
        return inserir_no_inicio(listaR, pegarUltimoNumero(soma));
    }
    else
    {
        *aux = 0;
        return inserir_no_inicio(listaR, intToChar(soma));
    }
}

//Função que libera memoria da lista
void libera(No *lista)
{
    if (lista != NULL)
    {
        libera(lista->prox);
        free(lista);
    }
}

int main()
{
    No *lista1 = NULL;
    No *lista2 = NULL;
    No *lista3 = NULL;
    int auxiliar1, auxiliar2, *auxiliar3 = (int *)malloc(sizeof(int));

    *auxiliar3 = 0;

    char numero1[30], numero2[30];
    int i;
    //Lê o primeiro numero
    printf("Digite o primeiro numero: ");
    scanf("%s", numero1);

    for (i = strlen(numero1) - 1; i >= 0; i--)
    {
        lista1 = inserir_no_inicio(lista1, numero1[i]);
    }
    //Lê o segundo número
    printf("Digite o segundo numero: ");
    scanf("%s", numero2);

    for (i = strlen(numero2) - 1; i >= 0; i--)
    {
        lista2 = inserir_no_inicio(lista2, numero2[i]);
    }

    auxiliar1 = strlen(numero1);
    auxiliar2 = strlen(numero2);

    //Armazena o resultado em uma terceira lista
    lista3 = func_soma(lista1, lista2, lista3, auxiliar1, auxiliar2, auxiliar3);

    if (*auxiliar3 == 1)
    {
        lista3 = inserir_no_inicio(lista3, '1');
    }
    //Imprime a lista
    imprimir_lista(lista3);

    libera(lista1);
    libera(lista2);
    libera(lista3);
    free(auxiliar3);

    return 0;
}