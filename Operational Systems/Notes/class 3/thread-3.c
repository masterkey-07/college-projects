#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

struct param_t
{
    int thread_id;
    int seconds;
};

typedef struct param_t param_t;

void *
thread_sleep(void *args)
{
    param_t *p = (param_t *)args;

    int *ret = (int *)calloc(1, sizeof(int));
    int i = 0;

    while (1)
    {
        printf("thread %d\n", p->thread_id);
        sleep(p->seconds);
        if (i == 10)
        {
            *ret = 10;
            pthread_exit(ret);
        }
        i++;
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t tid;

    param_t p = {0, 2};

    int *ret;

    pthread_create(&tid, NULL, thread_sleep, (void *)&p);

    pthread_join(tid, (void **)&ret);

    printf("%d\n", *ret);

    return 0;
}
