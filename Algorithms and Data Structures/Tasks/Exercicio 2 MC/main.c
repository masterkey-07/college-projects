#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

typedef struct Client
{
    int items;
} TClient;

typedef TClient *PClient;

typedef struct QueueClient
{
    int start;
    int length;
    PClient *clients;
} TQueueClient;

typedef TQueueClient *PQueueClient;

typedef struct Worker
{
    int items;
    int time;
} TWorker;

typedef TWorker *PWorker;

typedef struct QueueWorker
{
    int start;
    int length;
    PWorker *workers;
} TQueueWorker;

typedef TQueueWorker *PQueueWorker;

PQueueClient createQueueClient(int length)
{
    PQueueClient queue = (PQueueClient)malloc(sizeof(TQueueClient));
    queue->clients = (PClient *)malloc(sizeof(PClient) * length);
    queue->start = 0;
    queue->length = 0;

    return queue;
}

void pushClient(PQueueClient queue, int items)
{
    PClient client = (PClient)malloc(sizeof(TClient));

    client->items = items;

    queue->clients[queue->length] = client;

    queue->length++;
}

int popClient(PQueueClient queue)
{
    PClient client;
    int output;

    if (queue->length <= 0)
        return NULL;

    client = queue->clients[queue->start];

    output = client->items;

    free(client);

    queue->start++;
    queue->length--;

    return output;
}

PQueueWorker createQueueWorker(int length)
{
    PQueueWorker queue = (PQueueWorker)malloc(sizeof(TQueueWorker));
    queue->workers = (PWorker *)malloc(sizeof(PWorker) * length);
    queue->start = 0;
    queue->length = 0;

    return queue;
}

void pushWorker(PQueueWorker queue, int time)
{
    PWorker worker = (PWorker)malloc(sizeof(TWorker));

    worker->time = time;

    worker->items = 0;

    queue->workers[queue->length] = worker;

    queue->length++;
}

int main(int argc, char const *argv[])
{

    int number_workers, number_clients, i, input, result = 0, free_workers = 0, items = 0;
    PQueueWorker workerQueue;
    PQueueClient clientQueue;
    PWorker worker;

    scanf("%d", &number_workers);

    scanf("%d", &number_clients);

    workerQueue = createQueueWorker(number_workers);
    clientQueue = createQueueClient(number_clients);

    for (i = 0; i < number_workers; i++)
    {
        scanf("%d", &input);
        pushWorker(workerQueue, input);
    }

    for (i = 0; i < number_clients; i++)
    {
        scanf("%d", &input);
        pushClient(clientQueue, input);
    }

    while (TRUE)
    {
        free_workers = 0;
        for (i = 0; i < number_workers; i++)
        {
            worker = workerQueue->workers[i];
            if (worker->items == 0)
            {
                items = popClient(clientQueue);

                if (items == NULL)
                {
                    free_workers++;
                    continue;
                }

                worker->items = (worker->time * items) - 1;
            }
            else
                worker->items--;
        }

        if (free_workers == number_workers)
            break;
        else
            result++;
    }

    printf("%d", result);

    free(worker);
    return 0;
}