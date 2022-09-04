#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define CONDITION 4
#define PIPE 3
#define AND 2
#define BACKGROUND 1

int *format_commands(int argc, char **argv, char **tokens, int token_size, int *size, int *status)
{
    int i, j, st;
    *size = 1;
    for (i = 0; i < argc; i++)
        for (j = 0; j < token_size; j++)
            if (!strtok(argv[i], tokens[j]))
                (*size)++;

    int *positions = (int *)malloc(sizeof(int) * (*size));
    int index = 0;

    *(positions) = 1;

    for (i = 0; i < argc; i++)
        for (j = 0; j < token_size; j++)
            if (!strtok(argv[i], tokens[j]) && argv[i] != NULL)
            {
                st = (j * 2) + strlen(argv[i]);

                if (st > *status)
                    *status = st;

                *(positions + (++index)) = i + 1;
                argv[i] = NULL;
            }
    return positions;
}

int main(int argc, char const *argv[])
{
    int i, j, number_commands, type = 0, result;

    char *tokens[2] = {"&", "|"};

    int *commands_position = format_commands(argc, argv, tokens, 2, &number_commands, &type);

    if (type == 0)
        type = 3;

    char **command;

    pid_t pid;

    if (argc == 1)
    {
        printf("no arguments");
        return 0;
    }

    if (type == PIPE)
    {

        int fds[number_commands - 1][2];

        for (i = 0; i < number_commands - 1; i++)
            pipe(fds[i]);

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
        else if (fork() == 0)
        {
            command = &argv[*(commands_position)];
            execvp(command[0], command);
        }

        wait(NULL);
    }
    else if (type == BACKGROUND)
    {
        command = &argv[*(commands_position)];

        pid_t pid = fork();

        if (pid == 0)
            execvp(command[0], command);
    }
    else if (type == AND)
    {
        for (i = 0; i < number_commands; i++)
        {
            command = &argv[*(commands_position + i)];

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
    else if (type == CONDITION)
    {
        command = &argv[*(commands_position)];

        pid = fork();

        if (pid == 0)
        {
            execvp(command[0], command);

            return 1;
        }

        waitpid(pid, &result, 0);

        if (number_commands > 2)
            if (result == 0)
                i = 1;
            else
                i = 2;
        else if (result != 0)
            i = 1;
        else
            return 0;

        command = &argv[*(commands_position + i)];

        execvp(command[0], command);
    }

    return 0;
}
