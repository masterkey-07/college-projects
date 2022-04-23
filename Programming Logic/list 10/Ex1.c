#include <stdio.h>

int X(int n)
{
    printf("Hello World\n");

    if (n > 2)
        return X(n - 1) + X(n - 2) + X(n - 3);
    else
        return n;
}

int main()
{
    int r = X(6);

    printf("r = %d", r);

    return 0;
}

/*
1)
a) O valor de X(6) é igual a 20.

b) Foram feitas 25 chamadas na função X.
*/