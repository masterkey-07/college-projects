#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define N 10

int writer, reader;

sem_t mutex_producer; // mutex para rc entre produtores
sem_t mutex_consumer; // mutex para rc entre consumidores
sem_t full;           // indica qrtd posicoes cheias no buffer
sem_t empty;          // indica qtd de posicoes vaizas no buffer

int buffer[N];

void init(void)
{
    writer = 0;
    reader = 0;
    sem_init(&mutex_producer, 0, 1);
    sem_init(&mutex_consumer, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, N);
    srand(time(NULL));
}

int produce_item()
{
    return rand() % (N * 10);
}

void insert_item(int id, int item)
{
    buffer[writer] = item;
    printf("producer %d buffer[%d] = %d\n", id, writer, item);
    writer = (writer + 1) % N;
}

void *
producer(void *args)
{
    int id = *(int *)args;
    int item;
    while (1)
    {
        item = produce_item();
        sem_wait(&empty);
        sem_wait(&mutex_producer);
        insert_item(id, item);
        sem_post(&mutex_producer);
        sem_post(&full);
    }
}

int remove_item(int id)
{
    int item;
    item = buffer[reader];
    printf("consumer %d %d = buffer[%d]\n", id, item, reader);
    reader = (reader + 1) % N;
}

void *consumer(void *args)
{
    int id = *(int *)args;
    int item;
    while (1)
    {
        sem_wait(&full);
        sem_wait(&mutex_consumer);
        item = remove_item(id);
        sem_post(&mutex_consumer);
        sem_post(&empty);
    }
}

struct thread_t
{
    pthread_t th;
    int id;
};

typedef struct thread_t thread_t;

void create_threads(thread_t *th, int n, void *(*func)(void))
{
    int i;
    for (i = 0; i < n; i++)
    {
        th[i].id = i;
        pthread_create(&th[i].th, NULL, func, &th[i].id);
    }
}

void join_threads(thread_t *th, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        pthread_join(th[i].th, NULL);
    }
}

#define NP 20
#define NC 20

int main(int argc, char const *argv[])
{
    thread_t tp[NP], tc[NC];

    init();

    create_threads(tp, NP, producer);
    create_threads(tc, NC, consumer);

    join_threads(tc, NC);
    join_threads(tp, NP);

    return 0;
}
