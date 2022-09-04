#define TRUE 1
#define N 100
typedef int semaphone;
semaphone mutex = 1;
semaphone empty = N;
semaphone full = 0;

void producer(void)
{
    int item;
    while (TRUE)
    {
        item = produce_item();
        down(&empty);
        down(&mutex);
        insert_item(item);
        up(&mutex);
        up(&full);
    }
}

void consumer(void)
{
    int item;

    while (TRUE)
    {
        down(&full);
        down(&mutex);
        item = remove_item();
        up(&mutex);
        up(&full);
        consume_item(item);
    }
}