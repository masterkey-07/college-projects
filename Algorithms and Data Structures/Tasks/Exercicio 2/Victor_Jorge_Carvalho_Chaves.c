/*
Aluno: Victor Jorge Carvalho Chaves
R.A: 156.740
Turma: NB
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfSales;

struct Sale
{
    char productName[30];
    char buyer[30];
    int monthOfSale;
    int quantitySold;
};

// Retonar um Struct de venda com os dados que o usuário inseriu pelo terminal
struct Sale readSale(int pos)
{
    struct Sale sale;

    printf("\nDigite o nome do produto %d: ", pos);
    scanf("%s", sale.productName);

    printf("\nDigete a quantidade vendida: ");
    scanf("%d", &sale.quantitySold);

    printf("\nDigite o mes da venda (1-Jan, 2-Fev,...,12-Dez): ");
    scanf("%d", &sale.monthOfSale);

    printf("\nDigite o nome do comprador: ");
    scanf("%s", sale.buyer);

    return sale;
}

// Printa no terminal as opções que o usuário tem
int showMenu()
{
    int result;

    printf("\n1) Total de vendas num dado mes (de todos os produtos)\n");
    printf("\n2) Total de vendas de um determinado produto num dado mes para um determinado cliente\n");
    printf("\n3) Total de vendas de cada produto\n");
    printf("\n4) Total vendido para cada cliente\n");
    printf("\n5) Fim\n");
    scanf("%d", &result);

    return result;
}

// Lê o mês selecionado pelo usuário e faz o calculo e printa na tela o total de vendas desse mês
void allSalesInMonth(struct Sale *sales)
{
    int selectedMonth, i, salesSum = 0;
    printf("\nDigite o Mes (1-Jan, 2-Fev,...,12-Dez): ");
    scanf("%d", &selectedMonth);

    for (i = 0; i < numberOfSales; i++)
        if ((sales + i)->monthOfSale == selectedMonth)
            salesSum += (sales + i)->quantitySold;

    printf("\nO Total de Vendas no mes selecionado: %d\n", salesSum);
}

// Lê o mês, o produto e o comprador para depois calcular o total de vendas que ocorreu nessas condições
void allSalesByBuyerProductMonth(struct Sale *sales)
{
    int selectedMonth, i, salesSum = 0;
    char selectedProduct[30], selectedBuyer[30];

    printf("\nDigite o Produto: ");
    scanf("%s", selectedProduct);
    printf("\nDigite o Comprador: ");
    scanf("%s", selectedBuyer);
    printf("\nDigite o Mes (1-Jan, 2-Fev,...,12-Dez): ");
    scanf("%d", &selectedMonth);

    for (i = 0; i < numberOfSales; i++)
        if ((sales + i)->monthOfSale == selectedMonth && strcmp((sales + i)->productName, selectedProduct) == 0 && strcmp((sales + i)->buyer, selectedBuyer) == 0)
            salesSum += (sales + i)->quantitySold;

    printf("\nO Total de Vendas no mes selecionado: %d\n", salesSum);
}

// Printa na tela os total de vendas de cada produto
void allSalesForEachProduct(struct Sale *sales)
{
    int i, j, *quantitySales;
    char *product;
    int sum = 0;
    int result;
    product = (char *)malloc(30 * sizeof(char));

    for (i = 0; i < numberOfSales; i++)
    {
        product = (sales + i)->productName;
        sum = 0;

        for (j = 0; j < numberOfSales; j++)
        {
            result = strcmp(product, (sales + j)->productName);
            if (i > j && result == 0)
                break;
            else if (result == 0)
                sum += (sales + j)->quantitySold;
        }

        if (sum > 0)
            printf("\nO produto %s, teve um total de %d de vendas", product, sum);
    }

    printf("\n");
}

// Printa na tela o total de comprar de cada comprador
void allSalesForEachBuyer(struct Sale *sales)
{
    int i, j, *quantitySales, result;
    char *buyer;
    int sum = 0;

    buyer = (char *)malloc(30 * sizeof(char));

    for (i = 0; i < numberOfSales; i++)
    {
        buyer = (sales + i)->buyer;
        sum = 0;

        for (j = 0; j < numberOfSales; j++)
        {
            result = strcmp(buyer, (sales + j)->buyer);

            if (i > j && result == 0)
                break;
            else if (result == 0)
                sum += (sales + j)->quantitySold;
        }

        if (sum > 0)
            printf("\nO vendedor %s, teve um total de %d de compras", buyer, sum);
    }
}

// Executa todas as operações
int main(int argc, char const *argv[])
{
    int i, result;

    printf("\nDigite o numero de vendas: ");
    scanf("%d", &numberOfSales);

    struct Sale *sales;
    sales = (struct Sale *)malloc(numberOfSales * sizeof(struct Sale));

    for (i = 0; i < numberOfSales; i++)
        *(sales + i) = readSale(i + 1);

    while (1 == 1)
    {
        result = showMenu();

        if (result == 1)
            allSalesInMonth(sales);
        else if (result == 2)
            allSalesByBuyerProductMonth(sales);
        else if (result == 3)
            allSalesForEachProduct(sales);
        else if (result == 4)
            allSalesForEachBuyer(sales);
        else if (result == 5)
            break;
    }

    return 0;
}
