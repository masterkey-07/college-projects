#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <semaphore.h>
#include <pthread.h>

// CONSTANTS
#define INPUT_FILE "input.txt"
#define NUMBER_REDUCERS 26
#define NUMBER_MAPPERS 3
#define BUFFER_SIZE 100

// STRUCTS
struct word_counter
{
    char *key;
    int count;
};

typedef struct word_counter word_counter;

struct list_wc
{
    word_counter *wc;
    struct list_wc *next;
};

typedef struct list_wc list_wc;

struct list_text
{
    char *text;
    struct list_text *next;
};

typedef struct list_text list_text;

struct mapper_args
{
    int index;
    list_text **list;
    char ***buffer;
    sem_t **empty_buffer;
    sem_t **full_buffer;
    sem_t **mutex_sems;
    int **writer;
};

typedef struct mapper_args mapper_args;

struct reducer_args
{
    int index;
    list_text **list;
    char **buffer;
    sem_t *full_buffer;
    sem_t *empty_buffer;
    sem_t *mutex_sem;
    int *reader;
    list_wc *result;
};

typedef struct reducer_args reducer_args;

// FUNCTIONS
list_wc *count_word(list_wc *head, char *key)
{
    list_wc *new = NULL;

    if (head != NULL)
    {
        if (strcmp(head->wc->key, key) == 0)
            head->wc->count++;
        else
        {
            new = count_word(head->next, key);

            if (new != NULL)
                head->next = new;
        }

        return NULL;
    }
    else
    {
        list_wc *list = (list_wc *)malloc(sizeof(list_wc));

        list->wc = (word_counter *)malloc(sizeof(word_counter));

        list->wc->key = key;
        list->wc->count = 1;
        list->next = NULL;

        return list;
    }
}

list_text *push_text(list_text *head, char *text)
{

    list_text *new = (list_text *)malloc(sizeof(list_text));

    new->text = text;

    new->next = head;

    return new;
}

void post_item(char *token, mapper_args *map_args)
{
    int position;

    token[0] = tolower(token[0]);

    position = (int)token[0];

    position -= 97;

    sem_wait(map_args->empty_buffer[position]);
    sem_wait(map_args->mutex_sems[position]);

    map_args->buffer[position][*map_args->writer[position]] = token;
    *map_args->writer[position] = (*map_args->writer[position] + 1) % BUFFER_SIZE;

    sem_post(map_args->mutex_sems[position]);
    sem_post(map_args->full_buffer[position]);
}

int countlist(list_text *lt)
{

    if (lt != NULL)
        return 1 + countlist(lt->next);
    return 0;
}

void *mapper(void *args)
{
    mapper_args *map_args = (mapper_args *)args;

    char *text;

    int position;

    while (map_args->list[map_args->index] != NULL)
    {
        text = map_args->list[map_args->index]->text;

        map_args->list[map_args->index] = map_args->list[map_args->index]->next;

        char *token = strtok(text, " ");

        post_item(token, map_args);

        while (token)
        {
            token = strtok(NULL, " ");

            if (token != NULL)
                post_item(token, map_args);
        }
    }

    printf("DONE\n");
}

void consume_item(reducer_args *reduce_args)
{
    sem_wait(reduce_args->full_buffer);
    sem_wait(reduce_args->mutex_sem);

    printf("consume %c %s\n", (char)97 + reduce_args->index, reduce_args->buffer[*reduce_args->reader]);
    if (reduce_args->result == NULL)
        reduce_args->result = count_word(reduce_args->result, reduce_args->buffer[*reduce_args->reader]);
    else
        count_word(reduce_args->result, reduce_args->buffer[*reduce_args->reader]);

    *reduce_args->reader = (*reduce_args->reader + 1) % BUFFER_SIZE;

    sem_post(reduce_args->mutex_sem);
    sem_post(reduce_args->empty_buffer);
}

void *reducer(void *args)
{
    int i, stop = 1, status = 0;
    reducer_args *reduce_args = (reducer_args *)args;

    while (1)
    {
        printf("%d\n", reduce_args->index);

        while (status == 0)
        {
            printf("%d\n", reduce_args->index);
            stop = 1;
            sem_getvalue(reduce_args->full_buffer, &status);

            for (i = 0; i < NUMBER_MAPPERS; i++)
                if (reduce_args->list[i] != NULL)
                {
                    printf("%d\n", countlist(reduce_args->list[i]));
                    stop = 0;
                }
            if (stop == 1)
            {
                printf("dasdasdadsa\n");
                pthread_exit(NULL);
            }
        }

        consume_item(reduce_args);
    }
}

char *read_file(char *file_name)
{
    struct stat file_stat;

    stat(INPUT_FILE, &file_stat);

    char *text = (char *)malloc((sizeof(char) * file_stat.st_size) + 1);

    FILE *file;

    file = fopen(file_name, "rb");

    fread(text, sizeof(char), file_stat.st_size, file);

    fclose(file);

    return text;
}

int main(int argc, char const *argv[])
{
    char *text = read_file(INPUT_FILE);

    char *delimiter = ".,;?!\n";

    char *token = strtok(text, delimiter);

    int index = 0;

    list_text **list = (list_text **)malloc(sizeof(list_text *) * NUMBER_MAPPERS);

    list[index] = push_text(NULL, token);

    index = (index + 1) % NUMBER_MAPPERS;

    int c = 1;

    while (token)
    {
        list[index] = push_text(list[index], token);
        token = strtok(NULL, delimiter);
        index = (index + 1) % NUMBER_MAPPERS;
        c++;
    }

    c = countlist(list[0]);

    printf("count : %d\n", c);

    char ***buffer = (char ***)malloc(sizeof(char **) * NUMBER_REDUCERS);

    sem_t **full = (sem_t **)malloc(sizeof(sem_t **) * NUMBER_REDUCERS);
    sem_t **empty = (sem_t **)malloc(sizeof(sem_t **) * NUMBER_REDUCERS);
    sem_t **mutex = (sem_t **)malloc(sizeof(sem_t **) * NUMBER_REDUCERS);

    int **writer = (int **)malloc(sizeof(int *) * NUMBER_REDUCERS);
    int **reader = (int **)malloc(sizeof(int *) * NUMBER_REDUCERS);

    for (index = 0; index < NUMBER_REDUCERS; index++)
    {
        buffer[index] = (char **)malloc(sizeof(char *) * BUFFER_SIZE);

        full[index] = (sem_t *)malloc(sizeof(sem_t));
        empty[index] = (sem_t *)malloc(sizeof(sem_t));
        mutex[index] = (sem_t *)malloc(sizeof(sem_t));

        sem_init(full[index], 0, 0);
        sem_init(empty[index], 0, BUFFER_SIZE);
        sem_init(mutex[index], 0, 1);

        writer[index] = (int *)malloc(sizeof(int));
        reader[index] = (int *)malloc(sizeof(int));

        *writer[index] = 0;
        *reader[index] = 0;
    }

    mapper_args **map_args = (mapper_args **)malloc(sizeof(mapper_args *) * NUMBER_MAPPERS);
    reducer_args **reduce_args = (reducer_args **)malloc(sizeof(reducer_args *) * NUMBER_REDUCERS);

    pthread_t producers[NUMBER_MAPPERS];
    pthread_t consumers[NUMBER_REDUCERS];

    for (index = 0; index < NUMBER_MAPPERS; index++)
    {
        map_args[index] = (mapper_args *)malloc(sizeof(mapper_args));

        map_args[index]->index = index;
        map_args[index]->buffer = buffer;
        map_args[index]->empty_buffer = empty;
        map_args[index]->full_buffer = full;
        map_args[index]->list = list;
        map_args[index]->mutex_sems = mutex;
        map_args[index]->writer = writer;

        pthread_create(&producers[index], NULL, mapper, map_args[index]);
    }

    for (index = 0; index < NUMBER_REDUCERS; index++)
    {
        reduce_args[index] = (reducer_args *)malloc(sizeof(reducer_args));

        reduce_args[index]->buffer = buffer[index];
        reduce_args[index]->empty_buffer = empty[index];
        reduce_args[index]->full_buffer = full[index];
        reduce_args[index]->index = index;
        reduce_args[index]->list = list;
        reduce_args[index]->mutex_sem = mutex[index];
        reduce_args[index]->reader = reader[index];
        reduce_args[index]->result = NULL;

        pthread_create(&consumers[index], NULL, reducer, reduce_args[index]);
    }

    for (index = 0; index < NUMBER_MAPPERS; index++)
        pthread_join(&producers[index], NULL);

    list_wc *result;

    for (index = 0; index < NUMBER_REDUCERS; index++)
    {
        pthread_join(&consumers[index], NULL);

        result = reduce_args[index]->result;

        while (result != NULL)
        {
            printf("key : %s; count : %d\n", result->wc->key, result->wc->count);

            result = result->next;
        }
    }
    return 0;
}
