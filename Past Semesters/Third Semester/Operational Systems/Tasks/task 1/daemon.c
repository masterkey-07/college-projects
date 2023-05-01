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
            printf("HI\n");
            *(positions + (++index)) = i + 1;
            argv[i] = NULL;
        }
    return positions;
}

int main(int argc, char const *argv[])
{
    int number_commands;
    int *commands_position = format_commands(argc, argv, "&", &number_commands);
    char **command;

    command = &argv[*(commands_position)];

    pid_t pid = fork();

    if (pid == 0)
        execvp(command[0], command);

    return 0;
}
