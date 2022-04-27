#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    char **cmd;
    int ret;
    pid_t p;

    cmd = &argv[1];

    p = fork();

    if (p == 0)
    {
        printf("child %d p=%d", (int)getpid(), (int)p);
        execvp(cmd[0], cmd);
    }
    else
    {
        printf("father wait %d child %d", (int)getpid(), (int)p);
        waitpid(-1, &ret, 0);
    }

    return 0;
}
