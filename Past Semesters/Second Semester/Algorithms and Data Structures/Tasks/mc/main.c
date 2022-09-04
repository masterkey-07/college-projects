#include <stdio.h>
#include <stdlib.h>

/* Aluna: Maria Clara Galvao
    Período: Noturno
    RA: 156592 */

typedef struct Cliente
{
    double dinheiro, *precos;
    int quantidade;
} TCliente;

typedef TCliente *PCliente;

PCliente lerCliente()
{
    int i;

    PCliente cliente = (PCliente)malloc(sizeof(TCliente));
    if (cliente == NULL)
    {
        printf("Erro ao alocar!");
        exit(0);
    }

    do
    {
        scanf("%lf", &cliente->dinheiro);
    } while (cliente->dinheiro < 0);

    do
    {
        scanf("%d", &cliente->quantidade);
    } while (cliente->quantidade < 0 || cliente->quantidade > 100);

    cliente->precos = (double *)malloc(sizeof(double) * cliente->quantidade);

    for (i = 0; i < cliente->quantidade; i++)
        do
        {
            scanf("%lf", cliente->precos + i);
        } while ((cliente->precos + 1) < 0);

    return cliente;
}

void calcularCompra(PCliente cliente)
{
    double dinheiro, *precos;
    int quantidade, comprado, i;

    dinheiro = cliente->dinheiro;
    quantidade = cliente->quantidade;
    precos = cliente->precos;
    comprado = 0;

    for (i = 0; i < quantidade; i++)
        if (dinheiro - *(precos + i) >= 0.0)
        {
            dinheiro -= *(precos + i);
            comprado++;
        }
        else
            break;

    printf("%d %.2lf\n", comprado, dinheiro);
}

int main()
{
    int numeroCliente, i;

    do
    {
        scanf("%d", &numeroCliente);
    } while (numeroCliente > 100 || numeroCliente == 0 || numeroCliente < 0);

    PCliente *clientes = (PCliente *)malloc(sizeof(PCliente) * numeroCliente);

    for (i = 0; i < numeroCliente; i++)
        clientes[i] = lerCliente();

    for (i = 0; i < numeroCliente; i++)
        calcularCompra(clientes[i]);

    free(clientes);

    return 0;
}
