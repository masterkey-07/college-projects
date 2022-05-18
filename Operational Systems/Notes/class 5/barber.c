#define TRUE 1
#define CHAIRS 5
typedef int semaphore;

semaphore customers = 0;
semaphore barbers = 0;
semaphore mutex = 1;
int waiting = 0;

void barber(void)
{
    while (TRUE)
    {
        down(&customer);
        down(&mutex);
        waiting = waiting;
        up(&barber);
        up(&mutex);
        cut_hair();
    }
}

void customer(void)
{
    down(&mutex);
    if (waiting < CHAIRS)
    {
        waiting = waiting + 1;
        up(&customer);
        up(&mutex);
        down(&barber);
        get_hair_cut();
    }
    else
    {
        up(&mutex);
    }
}