#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h>
#include <string.h>

#define BUF_LEN 4096

int search_position(int argc, char **argv, char *token)
{
    int i;
    char *result = NULL;
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        result = strtok(argv[i], token);
        if (!result)
            return i;
    }

    return -1;
}

int main(int argc, char **argv)
{
    char **cmd, **cmd2;
    int ret;
    pid_t p;
    int fd[2];
    pipe(fd);

    int pos = search_position(argc, argv, "|");

    printf("position %d\n", pos);

    cmd = &argv[1];

    argv[pos] = NULL;

    cmd2 = &argv[pos + 1];

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
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        printf("father wait %d child %d\n", (int)getpid(), (int)p);
        waitpid(-1, &ret, 0);

        execvp(cmd2[0], cmd2);
        /*        char buffer[BUF_LEN];
                int n;

                do
                {
                    bzero(buffer, BUF_LEN);
                    n = read(fd[0], buffer, BUF_LEN);
                    printf("%s", buffer);
                } while (n > 0);
          */
    }

    return 0;
}
