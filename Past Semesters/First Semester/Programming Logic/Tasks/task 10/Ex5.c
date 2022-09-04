#include <stdio.h>

void switchNumbers(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    switchNumbers(&a, &b);

    printf("%d %d", a, b);

    return 0;
}
