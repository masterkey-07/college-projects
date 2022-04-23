#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sign_treatment(int sig)
{
    switch (sig)
    {
    case SIGINT:
        printf("dont stop");
        break;

    default:
        break;
    }

    return;
}

void nothing(int sig) { return; }

void my_sleep(int s)
{
    signal(SIGALRM, nothing);
    printf("%d sleeping...\n", s);
    alarm(s);
    pause();
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        signal(SIGINT, sign_treatment);
        printf("%d\n", getpid());
        my_sleep(1);
    }

    return 0;
}
