#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int index;
    int value;
};

typedef struct Item Item;

struct List
{
    int item;
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

Item **create_item_list(int length)
{
    return (Item **)malloc(sizeof(Item *) * length);
}

Item *create_item(int value, int index)
{
    Item *item = (Item *)malloc(sizeof(Item));

    item->index = index;
    item->value = value;

    return item;
}

Queue *create_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->length = 0;
    queue->front = NULL;
    queue->end = NULL;

    return queue;
}

List *create_list(int item)
{
    List *list = (List *)malloc(sizeof(List));

    list->item = item;
    list->next = NULL;

    return list;
}

void push(Queue *queue, int item)
{
    queue->length++;

    if (queue->length == 1)
    {
        List *new_list = create_list(item);

        queue->front = new_list;
        queue->end = new_list;
    }
    else
    {
        List *new_list = create_list(item);

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
    int length, input, i, j;

    Queue **queues = (Queue **)malloc(sizeof(Queue *) * number_list);

    for (i = 0; i < number_list; i++)
    {
        scanf("%d", &length);

        *total += length;

        queues[i] = create_queue();

        for (j = 0; j < length; j++)
        {
            scanf("%d", &input);
            push(queues[i], input);
        }
    }

    return queues;
}

Item **build_items(int number_list, Queue **queues, int total)
{
    int index = 0, i;

    Item **items = create_item_list(total);

    List *list;

    for (i = 0; i < number_list; i++)
    {
        list = queues[i]->front;

        while (list != NULL)
        {
            items[index] = create_item(list->item, i);
            list = list->next;

            index++;
        }
    }

    return items;
}

void merge(Item **array, int start, int middle, int end)
{
    int length_a = middle - start + 1;
    int length_b = end - middle;

    int i, j, k;

    Item **items_a = create_item_list(length_a);

    Item **items_b = create_item_list(length_b);

    for (i = 0; i < length_a; i++)
        items_a[i] = array[start + i];

    for (i = 0; i < length_b; i++)
        items_b[i] = array[middle + i + 1];

    i = 0;
    j = 0;
    k = start;

    while (i < length_a && j < length_b)
        if (items_a[i]->value <= items_b[j]->value)
            array[k++] = items_a[i++];
        else
            array[k++] = items_b[j++];

    while (i < length_a)
        array[k++] = items_a[i++];

    while (j < length_b)
        array[k++] = items_b[j++];
}

void merge_sort(Item **array, int start, int end)
{
    if (end <= start)
        return;

    int middle = (start + end) / 2;

    merge_sort(array, start, middle);
    merge_sort(array, middle + 1, end);
    merge(array, start, middle, end);
}

int main(int argc, char const *argv[])
{
    int number_list, iterations, index, total = 0;

    scanf("%d", &number_list);
    scanf("%d", &iterations);

    Queue **queues = build_queues(number_list, &total);

    Item **items = build_items(number_list, queues, total);

    merge_sort(items, 0, total - 1);

    for (index = 0; index < iterations - 1; index++)
        dequeue(queues[items[index]->index]);

    int sum = 0;

    for (index = 0; index < number_list; index++)
        sum += dequeue(queues[index]);

    printf("%d", sum);

    return 0;
}
