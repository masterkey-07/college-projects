#include <stdio.h>

int getMax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int getMin(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int getNumberPrime(int number, int number2)
{
    int count, i;
    number++;

    while (1 == 1)
    {
        count = 0;

        for (i = 1; i <= number2; i++)
            if ((number % i == 0) && (number2 % i == 0))
                count++;

        if (count == 1)
            break;

        number++;
    }

    return number;
}

int isPrimeNumber(int number)
{
    int count = 0, i;

    for (i = 1; i <= number; i++)
        if (number % i == 0)
            count++;

    if (count < 3)
        return 1;
    else
        return 0;
}

int readInt()
{
    int integer;

    scanf("%d", &integer);

    return integer;
}

void LeABC(int *a, int *b, int *c)
{
    *a = readInt();
    *b = readInt();
    *c = readInt();
}

void Calcula_XY(int b, int c, int *x, int *y)
{
    *x = b + 1;

    *y = getNumberPrime(c, (*x));
}

void Calcula_QR(int a, int b, int *q, int *r)
{
    if (a > b)
    {
        *q = a / b;
        *r = 1 + (a % b);
    }
    else if (b > a)
    {
        *q = b / a;
        *r = 1 + (b % a);
    }
    else
    {
        *q = 20 * a;
        *r = 5;
    }
}

int Calcula_Z(int q, int r)
{
    int i, number;

    number = getMin(q, r);

    for (i = number; i >= 1; i--)
        if (isPrimeNumber(i))
            return i;

    return 1;
}

int Calcula_P(int x, int y, int z)
{
    return x + (z - 1) * y;
}

int Calcula_S(int m, int p, int q, int r, int x, int y)
{

    return ((m * p) / getMax(x, y)) + getMin(q, r);
}

int main()
{
    int m, a, b, c, x, y, q, r, z, p, s;

    m = readInt();

    LeABC(&a, &b, &c);

    Calcula_XY(b, c, &x, &y);

    Calcula_QR(a, b, &q, &r);

    z = Calcula_Z(q, r);

    p = Calcula_P(x, y, z);

    s = Calcula_S(m, p, q, r, x, y);

    printf("%d", s);

    return 0;
}