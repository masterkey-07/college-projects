#define TRUE 1
#define N 100

void producer(void)
{
    int item;

    message m;

    while (TRUE)
    {
        item = produce_item();
        receive(consumer, &m);
        build_message(&m, item);
        send(consumer, &m);
    }
}

void consumer(void)
{
    int item, i;
    message m;

    for (i = 0; i < N; i++)
        send(producer, &m);

    while (TRUE)
    {
        receive(producer, &m);
        item = extract_item(&m);
        send(producer, &m);
        consume_item(item);
    }
}