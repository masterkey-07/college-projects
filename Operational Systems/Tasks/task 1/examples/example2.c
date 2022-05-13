#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h>

#define BUF_LEN 4096

int main(int argc, char **argv)
{
    char **cmd;
    int ret;
    pid_t p;
    int fd[2];
    pipe(fd);

    cmd = &argv[1];

    p = fork();

    if (p == 0)
    {
        printf("child %d p=%d\n", (int)getpid(), (int)p);
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execvp(cmd[0], cmd);
    }
    else
    {
        printf("father wait %d child %d\n", (int)getpid(), (int)p);
        waitpid(-1, &ret, 0);
        char buffer[BUF_LEN];
        int n;
        do
        {
            bzero(buffer, BUF_LEN);
            n = read(fd[0], buffer, BUF_LEN);
            printf("%s", buffer);
        } while (n > 0);

        close(fd[0]);
    }

    return 0;
}
