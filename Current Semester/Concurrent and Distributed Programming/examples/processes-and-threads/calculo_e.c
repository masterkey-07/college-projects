#include <stdio.h>
#include <pthread.h>

#define N 1000000000
#define MAX_THREADS 4

void *calcula(void *res)
{
    int k;
    double p = 1, x, y;
    x = 1 + 1.0 / N;
    for (k = 0; k < (N / MAX_THREADS); k++)
        p = p * x;
    // copia valor p/variável de retorno
    *((double *)res) = p;
}
int main(void)
{
    pthread_t t[MAX_THREADS];
    double v[MAX_THREADS];
    double final;
    int i;

    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_create(&t[i], NULL,
                       calcula,
                       (void *)&v[i]);
    }

    final = 1.;
    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(t[i], NULL);
        final = final * v[i];
    }

    printf("Resultado=%lf\n", final);
    return 0;
}
