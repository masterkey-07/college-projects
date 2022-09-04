#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int *format_commands(int argc, char **argv, char **token, int token_size, int *size, int *status)
{
    int i, j;
    *size = 1;
    for (i = 0; i < argc; i++)
        for (j = 0; j < token_size; j++)
            if (!strtok(argv[i], token[j]))
                (*size)++;

    int *positions = (int *)malloc(sizeof(int) * (*size));
    int index = 0;

    *(positions) = 1;

    for (i = 0; i < argc; i++)
        for (j = 0; j < token_size; j++)
            if (!strtok(argv[i], token[j]) && argv[i] != NULL)
            {
                if (j > *status)
                    *status = j;

                *(positions + (++index)) = i + 1;
                argv[i] = NULL;
            }
    return positions;
}

int main(int argc, char const *argv[])
{
    int i, number_commands, type = 0, result;

    char *tokens[2] = {"&&", "||"};

    int *commands_position = format_commands(argc, argv, tokens, 2, &number_commands, &type);

    char **command;

    pid_t pid;

    if (type == 0)
    {
        for (i = 0; i < number_commands; i++)
        {
            command = &argv[*(commands_position + i)];

            fflush(stdout);

            pid = fork();

            if (pid == 0)
            {
                execvp(command[0], command);
                return 1;
            }
            waitpid(pid, &result, 0);

            if (result != 0)
                break;
        }
    }
    else
    {
        command = &argv[*(commands_position)];

        pid = fork();

        if (pid == 0)
        {
            execvp(command[0], command);
            return 1;
        }

        waitpid(pid, &result, 0);

        if (result == 0)
            i = 2;
        else
            i = 3;

        command = &argv[*(commands_position + i)];

        execvp(command[0], command);
    }

    return 0;
}
