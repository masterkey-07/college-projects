#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_sleep(void *args)
{
    while (1)
    {
        printf("thread\n");
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread_sleep, NULL);

    pthread_join(tid, NULL);
    return 0;
}
