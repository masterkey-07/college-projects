#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_sleep(void *args)
{
    int *ret = (int *)calloc(1, sizeof(int));
    int i = 0;

    while (1)
    {
        printf("thread\n");
        sleep(1);
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

    int *ret;

    pthread_create(&tid, NULL, thread_sleep, NULL);

    pthread_join(tid, (void **)&ret);

    printf("%d\n", *ret);

    return 0;
}
