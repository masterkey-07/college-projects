#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUF_LEN 16384

int run_command(char **command)
{
    execvp(command[0], command);

    return 0;
}

void test(int fd[2])
{
    char buffer[BUF_LEN];
    int n;

    do
    {
        bzero(buffer, BUF_LEN);
        n = read(fd[0], buffer, BUF_LEN);
        printf("%s", buffer);
    } while (n > 0);
}

int *format_commands(int argc, char **argv, char *token, int *size)
{
    int i;
    *size = 1;
    for (i = 0; i < argc; i++)
        if (!strtok(argv[i], token))
            (*size)++;

    int *positions = (int *)malloc(sizeof(int) * (*size));
    int index = 0;

    *(positions) = 1;

    for (i = 0; i < argc; i++)
        if (!strtok(argv[i], token))
        {
            *(positions + (++index)) = i + 1;
            argv[i] = NULL;
        }
    return positions;
}

void dup_fd(int fd[2], int sign)
{
    if (sign == STDOUT_FILENO)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
    }
}

int main(int argc, char const *argv[])
{
    int i, number_commands, j;
    int *commands_position = format_commands(argc, argv, "|", &number_commands);
    int fd[2];
    int fd2[2];
    int ret;

    pipe(fd);
    pipe(fd2);

    pid_t pid[number_commands];

    char **command;

    for (i = 0; i < number_commands - 1; i++)
    {
        command = &argv[*(commands_position + i)];

        pid[i] = fork();

        int ret;

        if (pid[i] == 0)
        {
            dup_fd(fd, STDOUT_FILENO);

            run_command(command);
        }

        dup_fd(fd, STDIN_FILENO);
    }

    command = &argv[*(commands_position + i)];

    run_command(command);

    return 0;
}
