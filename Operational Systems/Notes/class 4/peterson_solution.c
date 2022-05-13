#define FALSE 0
#define TRUE 1
#define N 2

int turn;
int interested[N];

void enter_region(int process)
{
    int other;

    other = 1 - process;

    interested[process] = TRUE;

    turn = process;

    while (turn == process && interested[other] == TRUE)
    {
    }
}

void leave_region(int process)
{
    interested[process] = FALSE;
}