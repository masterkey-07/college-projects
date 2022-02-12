#include <stdio.h>
#include <string.h>

struct product
{
    int code;
    char name[100];
    double price;
    int quantity;
};
int main()
{
    struct product Product[50];
    int N, i, code = -1, quantity;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d %s %lf %d", &Product[i].code, &Product[i].name, &Product[i].price, &Product[i].quantity);

    while (1 == 1)
    {
        scanf("%d %d\n", &code, &quantity);

        if (code == 0)
            break;

        for (i = 0; i < N; i++)
        {
            if (Product[i].code == code)
            {
                if (Product[i].quantity < quantity)
                {
                    printf("Estoque insuficiente\n");
                    break;
                }
                Product[i].quantity -= quantity;
                printf("Pedido atendido, estoque atualizado:\n");
                printf("%d %s %lf %d\n", Product[i].code, Product[i].name, Product[i].price, Product[i].quantity);
                break;
            }
        }

        if (Product[i].code != code)
            printf("Produto não encontrado\n");
    }

    return 0;
}
