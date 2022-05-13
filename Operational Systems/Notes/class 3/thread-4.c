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
    param_t *param = (param_t *)args;

    int *output = (int *)calloc(1, sizeof(int));
    int i = 0;

    while (1)
    {
        printf("thread %d\n", param->thread_id);
        sleep(param->seconds);
        if (i == 10)
        {
            *output = param->thread_id * 10;
            pthread_exit(output);
        }
        i++;
    }

    pthread_exit(NULL);
}

#define MAX_T 4

int main(int argc, char const *argv[])
{
    int *output, i;

    pthread_t thread_ids[MAX_T];

    param_t params[MAX_T];

    for (i = 0; i < MAX_T; i++)
    {
        params[i].thread_id = i;

        if (i % 2 == 0)
            params[i].seconds = 1;
        else
            params[i].seconds = 2;

        pthread_create(&thread_ids[i], NULL, thread_sleep, (void *)&params[i]);
    }

    for (i = 0; i < MAX_T; i++)
    {
        pthread_join(thread_ids[i], (void **)&output);
        printf("%d\n", *output);
    }

    return 0;
}
