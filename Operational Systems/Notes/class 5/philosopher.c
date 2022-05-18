#define N 5

void philosopher(int i)
{
	while (TRUE)
	{
		think();
		take_fork(i);
		take_fork((i + 1) % N);
		eat();
		put_fork(i);
		put_fork((i + 1) % N);
	}
}
