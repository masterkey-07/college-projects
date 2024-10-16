#include <stdio.h>
#include <sys/types.h>

#define MAX_COUNT 10

void ChildProcess(void)
{
    int i, pid, parent;

    pid = getpid();
    parent = getppid();
    for (i = 1; i <= MAX_COUNT; i++)
        printf(" child, value=%d\n", i);
    printf(" *** Child process (PID: %d, parent: %d) is done ***\n", pid, parent);
}

void ParentProcess(void)
{
    int i, pid, parent;

    pid = getpid();
    parent = getppid();
    for (i = 1; i <= MAX_COUNT; i++)
        printf("parent, value=%d\n", i);
    printf("*** Parent (PID: %d, parent: %d) is done ***\n",
           pid, parent);
}

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) /* erro */
        perror("impossivel de criar um filho\n");
    else if (pid == 0)
        ChildProcess();
    else
        ParentProcess();

    return 0;
}
