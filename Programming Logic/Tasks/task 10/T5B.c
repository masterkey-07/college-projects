#include <stdio.h>
#include <stdlib.h>

void LeABC(int *a, int *b, int *c)
{

    int n1, n2, n3;

    scanf("\n %d %d %d", &n1, &n2, &n3);

    *a = n1;
    *b = n2;
    *c = n3;
}

void Calcula_XY(int b, int c, int *x, int *y)
{
    int contador2, contador;
    *x = b + 1;

    c++;

    while (1 == 1)
    {
        contador2 = 0;

        for (contador = 1; contador <= *x; contador++)
            if ((c % contador == 0) && (*x % contador == 0))
                contador2++;

        if (contador2 == 1)
            break;

        c++;
    }

    *y = c;
}
void Calcula_QR(int a, int b, int *q, int *r)
{

    if (a > b)
    {
        *q = a / b;
        *r = (a % b) + 1;
    }
    else if (a == b)
    {
        *q = 20 * a;
        *r = 5;
    }
    else
    {
        *q = b / a;
        *r = (b % a) + 1;
    }
}

int Calcula_Z(int q, int r)
{
    int minimo, contador;

    if (q > r)
        minimo = r;
    else
        minimo = q;

    for (contador = minimo; contador >= 1; contador--)
    {
        if (verificarSeEPrimo(contador) == 0)
        {
            return contador;
        }
    }

    return 1;
}

int verificarSeEPrimo(int numero)
{
    int contador2 = 0, contador;

    for (contador = 1; contador <= numero; contador++)
    {
        if (numero % contador == 0)
        {
            contador2++;
        }
    }

    if (contador2 <= 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Calcula_P(int x, int y, int z)
{
    int formula;

    formula = x + ((z - 1) * y);

    return formula;
}

int Calcula_S(int m, int p, int q, int r, int x, int y)
{
    int menor, maior, calculoS;

    if (q > r)
    {
        menor = q;
    }
    else
    {
        menor = r;
    }

    if (x > y)
    {
        maior = x;
    }
    else
    {
        maior = y;
    }

    calculoS = ((m * p) / maior) + menor;

    return calculoS;
}

int main()
{
    int m, a, b, c, x, y, q, r, z, p, s;

    scanf("%d", &m);

    LeABC(&a, &b, &c);

    Calcula_XY(b, c, &x, &y);

    Calcula_QR(a, b, &q, &r);

    z = Calcula_Z(q, r);

    p = Calcula_P(x, y, z);

    s = Calcula_S(m, p, q, r, x, y);

    printf("%d", s);

    return 0;
}
