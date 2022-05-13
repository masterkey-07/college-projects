#include <stdio.h>
#include <pthread.h>
#define TRUE 1
#define FALSE 0

int turn = 0;

void critical_region(int id)
{
    printf("critical %d; %d\n", id, turn);
    fflush(stdout);
}

void non_critical_region(int id)
{
    printf("non critical %d; %d\n", id, turn);
    fflush(stdout);
}

int change(int t)
{
    if (t == 0)
        return 1;
    else
        return 0;
}

void *my_process(void *args)
{
    int id = *(int *)args;
    while (TRUE)
    {
        while (turn != id)
            critical_region(id);

        turn = change(turn);
        non_critical_region(id);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t0, t1;

    int id0 = 0, id1 = 1;

    pthread_create(&t0, NULL, my_process, &id0);
    pthread_create(&t1, NULL, my_process, &id1);
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    return 0;
}
