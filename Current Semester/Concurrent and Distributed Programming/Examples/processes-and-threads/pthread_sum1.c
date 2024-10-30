#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 12
#define ARRAY_SIZE 10000

int array[ARRAY_SIZE];
int sum = 0;
sem_t mutex;

// Função executada por cada thread
void *thread_sum(void *thread_id)
{
    long tid = (long)thread_id;
    int chunk_size = ARRAY_SIZE / NUM_THREADS;
    int start = tid * chunk_size;
    int end = start + chunk_size;

    for (int i = start; i < end; i++)
    {
        sem_wait(&mutex);
        sum += array[i];
        sem_post(&mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    sem_init(&mutex, 0, 1);

    // Preenche o array com valores de exemplo
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = i + 1;
    }

    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++)
    {
        rc = pthread_create(&threads[t], NULL, thread_sum, (void *)t);
        if (rc)
        {
            printf("Erro ao criar a thread %ld\n", t);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    printf("Soma total: %d\n", sum);

    pthread_exit(NULL);
}
