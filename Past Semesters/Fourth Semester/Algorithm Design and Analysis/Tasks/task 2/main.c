#include <stdio.h>
#include <stdlib.h>

struct List
{
    int item;
    int index;
    struct List *next;
};

typedef struct List List;

struct Queue
{
    int length;
    struct List *front;
    struct List *end;
};

typedef struct Queue Queue;

List *create_list(int item, int index, List *next)
{
    List *list = (List *)malloc(sizeof(List));

    list->item = item;
    list->index = index;
    list->next = next;

    return list;
}

Queue *create_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->length = 0;
    queue->front = NULL;
    queue->end = NULL;

    return queue;
}

void push(Queue *queue, int item, int index)
{
    List *new_list = create_list(item, index, NULL);

    queue->length++;

    if (queue->length == 1)
    {
        queue->front = new_list;
        queue->end = new_list;
    }
    else
    {
        queue->end->next = new_list;
        queue->end = new_list;
    }
}

int dequeue(Queue *queue)
{
    if (queue->length == 0)
        return 0;

    queue->length--;

    if (queue->length == 0)
    {
        List *list = queue->front;

        int output = list->item;

        free(list);

        queue->front = NULL;
        queue->end = NULL;

        return output;
    }
    else
    {
        List *list = queue->front;

        queue->front = list->next;

        int output = list->item;

        free(list);

        return output;
    }
}

Queue **build_queues(int number_list, int *total)
{
    int length, input, index, i;

    Queue **queues = (Queue **)malloc(sizeof(Queue *) * number_list);

    for (index = 0; index < number_list; index++)
    {
        scanf("%d", &length);

        *total += length;

        queues[index] = create_queue();

        for (i = 0; i < length; i++)
        {
            scanf("%d", &input);
            push(queues[index], input, index);
        }
    }

    return queues;
}

List *merge(List *list, List *append)
{
    if (append == NULL)
        return list;

    if (list == NULL)
        return create_list(append->item, append->index, merge(list, append->next));

    if (list->item > append->item)
        return create_list(append->item, append->index, merge(list, append->next));

    list->next = merge(list->next, append);

    return list;
}

int main(int argc, char const *argv[])
{
    int number_list, iterations, index, total = 0;

    scanf("%d", &number_list);
    scanf("%d", &iterations);

    Queue **queues = build_queues(number_list, &total);

    int output = 0;

    List *list = NULL;

    for (index = 0; index < number_list; index++)
        list = merge(list, queues[index]->front);

    for (index = 1; index < iterations; index++)
    {
        dequeue(queues[list->index]);
        list = list->next;
    }

    for (index = 0; index < number_list; index++)
        output += dequeue(queues[index]);

    printf("%d", output);

    return 0;
}
