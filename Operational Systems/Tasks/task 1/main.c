#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "test.c"

static int *glob_var;

int main(void)
{

    glob_var = create_mmap();

    *glob_var = 1;

    pid_t pid = fork();
    int ret;
    if (pid == 0)
    {
        *glob_var = 5;
        exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(-1, &ret, 0);
        printf("%d\n", *glob_var);
        munmap(glob_var, sizeof *glob_var);
    }
    return 0;
}