#include <stdio.h>
#include <stdlib.h>

typedef char *word;

typedef word *list_word;

list_word *createAlphBuffer()
{
    return (list_word *)malloc(sizeof(list_word) * 26);
}

//