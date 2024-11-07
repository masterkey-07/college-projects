#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 0;

    char const *file_name = argv[1];

    FILE *file = fopen(file_name, "rb");

    if (file == NULL)
        return 0;

    file_buffer *buffer = allocate_buffer(file);

    lexem_buffer *lexem = allocate_lexem_buffer();

    while (get_next_lexem(buffer, lexem) == 1)
        printf("Type:%d\tLexem:%s\tLine:%d\n", lexem->token, lexem->data, lexem->line);

    deallocate_buffer(buffer);

    deallocate_lexem_buffer(lexem);

    fclose(file);

    printf("done\n");

    return 0;
}
