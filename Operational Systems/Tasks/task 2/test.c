#include <stdio.h>
#include <stdlib.h>

struct key
{
    int *key;
};

typedef struct key key;

void change(key **k, int i)
{
    k[i] = (key *)malloc(sizeof(k));

    k[i]->key = 45;
}

int main(int argc, char const *argv[])
{
    char *x = "abc";

    printf("%s\n", x);

    x = "dsdsads";

    printf("%s\n", x);

    return 0;
}
