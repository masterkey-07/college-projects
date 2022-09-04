#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int *a, int *b, int n, int k)
{
    int *c = (int *)malloc(sizeof(int) * k);

    int i;

    for (i = 0; i < k; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
        c[a[i]]++;

    for (i = 1; i < k; i++)
        c[i] += c[i - 1];

    for (i = n - 1; i >= 0; i--)
        b[--c[a[i]]] = a[i];
}

int main(int argc, char const *argv[])
{
    int n, *a, *b, i;

    scanf("%d", &n);

    a = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    bucket_sort(a, b, n, k);

    for (i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}
