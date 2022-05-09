#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente
{
    double dinheiro, *precos;
    int quantidade;
} TCliente;

typedef TCliente *PCliente;

PCliente lerCliente()
{
    PCliente cliente = (PCliente)malloc(sizeof(TCliente));

    int i, j;

    scanf("%lf", &cliente->dinheiro);
    scanf("%d", &cliente->quantidade);

    cliente->precos = (double *)malloc(sizeof(double) * cliente->quantidade);

    for (j = 0; j < cliente->quantidade; j++)
        scanf("%lf", cliente->precos + j);

    return cliente;
}

void calcularCompra(PCliente cliente)
{
    double dinheiro, *precos;
    int quantidade, comprado, i, j;

    dinheiro = cliente->dinheiro;
    quantidade = cliente->quantidade;
    precos = cliente->precos;
    comprado = 0;

    for (j = 0; j < quantidade; j++)
    {
        if (dinheiro - *(precos + j) >= 0.0)
        {
            dinheiro -= *(precos + j);
            comprado++;
        }
        else
            break;
    }

    printf("%d %.2lf\n", comprado, dinheiro);
}

int main(int argc, char const *argv[])
{
    int numeroCliente, i;

    scanf("%d", &numeroCliente);

    PCliente *clientes = (PCliente *)malloc(sizeof(PCliente) * numeroCliente);

    for (i = 0; i < numeroCliente; i++)
        clientes[i] = lerCliente();

    for (i = 0; i < numeroCliente; i++)
        calcularCompra(clientes[i]);

    free(clientes);

    return 0;
}
