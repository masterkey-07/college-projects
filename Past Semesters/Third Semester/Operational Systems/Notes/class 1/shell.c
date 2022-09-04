#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>>

int main(int argc, char const *argv[])
{
    int p, s;

    p = fork();

    printf("%d\n", p);

    if (p == 0)
        execvp("ls", "la");
    else
        waitpid(-1, &s, 0);

    return 0;
}
