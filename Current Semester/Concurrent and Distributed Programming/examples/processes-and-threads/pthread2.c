#include <stdio.h>
#include <pthread.h>

#define MAX_COUNT 10
#define MAX_THREADS 3

void *ThreadProcess(void *th); /* thread process prototype */

int main(void)
{
    pthread_t t[MAX_THREADS]; // duas threads
    int i;

    for (i = 0; i < MAX_THREADS; i++)
        pthread_create(&t[i], NULL, ThreadProcess, (void *)(i + 1));

    pthread_exit(NULL);
}

void *ThreadProcess(void *th)
{
    int i, thid;

    thid = (int)th;
    for (i = 1; i <= MAX_COUNT; i++)
        printf("Line from thread %d,value=%d\n", thid, i);

    pthread_exit(NULL);
}
