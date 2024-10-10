#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"

struct char_buffer allocate_buffer(int buffer_size)
{
    struct char_buffer new_buffer;

    new_buffer.size = buffer_size;
    new_buffer.data = (char *)malloc(sizeof(char) * buffer_size);

    return new_buffer;
}

void deallocate_buffer(struct char_buffer buffer)
{
    free(buffer.data);
}

int replace(char character)
{
    if (character == 65)
        return 65 + 32;

    if (character == 69)
        return 69 + 32;

    if (character == 73)
        return 73 + 32;

    if (character == 79)
        return 79 + 32;

    if (character == 85)
        return 85 + 32;

    if (character == 65 + 32)
        return 65;

    if (character == 69 + 32)
        return 69;

    if (character == 73 + 32)
        return 73;

    if (character == 79 + 32)
        return 79;

    if (character == 85 + 32)
        return 85;

    return character;
}

void replace_print(FILE *file, struct char_buffer bf)
{
    while (fread(bf.data, sizeof(char), bf.size, file))
        for (int index = 0; index < bf.size; index++)
            if (bf.data[index] != '\0')
                printf("%c", replace(bf.data[index]));
}
