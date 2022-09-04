#include <string.h>

struct WordCounter
{
    char *key;
    int count;
};

struct ListWC
{
    struct WordCounter *wordCounter;

    struct ListWC *next;
};

struct ListWC *countWord(struct ListWC *first, char *word)
{

    struct ListWC *result;
    if (first == NULL)
        return createListWC(word);

    if (strcmp(first->wordCounter->key, word))
        first->wordCounter->count++;
    else
    {
        result = countWord(first->next, word);

        if (result)
            first->next = result;

        return NULL;
    }
}

struct WordCounter *collect(struct ListWC *first, struct WordCounter *output)
{
    if (first)
    {
        struct ListWC *next;

        next = first->next;

        output = first->wordCounter;

        free(first);

        return next;
    }
}

/*

while (list){
   output = collect(list);
   write(output);
}


*/