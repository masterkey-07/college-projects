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
    key *k = (key *)malloc(sizeof(k));
    k->key = (int *)malloc(sizeof(int));
    k->key = 0;

    key *ka = (key *)malloc(sizeof(k));
    ka->key = (int *)malloc(sizeof(int));
    ka->key = 1;

    key *kb = (key *)malloc(sizeof(k));
    kb->key = (int *)malloc(sizeof(int));
    kb->key = 2;

    key **kl = (key **)malloc(sizeof(*k) * 3);

    kl[0] = k;
    kl[1] = ka;
    kl[2] = kb;

    change(kl, 2);

    printf("%d\n", kl[2]->key);

    return 0;
}
