#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void run_command(char **command)
{
    execvp(command[0], command);
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

int main(int argc, char const *argv[])
{
    int i, number_commands;
    int *commands_position = format_commands(argc, argv, "|", &number_commands);
    int fd[2];
    int fd2[2];
    pid_t pid;
    char **command;

    for (i = 0; i < number_commands; i++)
    {
        command = &argv[*(commands_position + i)];

        pid = fork();

        int ret;

        if (pid != 0)
        {
            if (i == number_commands - 1)
            {
            }
            else
            {
                printf("HI A\n");
                close(fd[1]);
                dup2(fd[0], STDIN_FILENO);
                close(fd[0]);
                waitpid(-1, &ret, 0);
            }
        }
        else if (i == 0)
        {
            printf("HI B\n");
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            execvp(command[0], command);
        }
        else if (i == number_commands - 1)
        {
            printf("HI C\n");
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            run_command(command);
        }
        else
        {
        }
        break;
    }

    return 0;
}
