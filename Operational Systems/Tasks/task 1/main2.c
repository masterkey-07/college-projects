#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

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
    int i, number_commands, j;
    int *commands_position = format_commands(argc, argv, "|", &number_commands);
    int fds[number_commands - 1][2];
    int ret;

    for (i = 0; i < number_commands - 1; i++)
        pipe(fds[i]);

    char **command;

    if (number_commands > 1)
    {
        for (i = 0; i < number_commands; i++)
        {
            command = &argv[*(commands_position + i)];

            if (fork() == 0)
            {
                for (j = 0; j < number_commands - 1; j++)
                {
                    if (j != i)
                        close(fds[j][1]);

                    if (j != i - 1)
                        close(fds[j][0]);
                }

                if (i > 0)
                {
                    dup2(fds[i - 1][0], STDIN_FILENO);
                    close(fds[i - 1][0]);
                }

                if (i < number_commands - 1)
                {
                    dup2(fds[i][1], STDOUT_FILENO);
                    close(fds[i][1]);
                }

                execvp(command[0], command);
            }
        }
    }
    else
    {
        if (fork() == 0)
        {
            command = &argv[*(commands_position)];
            execvp(command[0], command);
        }
    }

    return 0;
}
