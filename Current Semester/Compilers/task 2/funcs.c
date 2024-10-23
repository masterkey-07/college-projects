#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"

struct file_buffer *allocate_buffer()
{
    file_buffer *new_buffer = (file_buffer *)malloc(sizeof(file_buffer));

    new_buffer->line = 1;
    new_buffer->index = 0;
    new_buffer->data = (char *)malloc(BUFFER_SIZE);

    return new_buffer;
}

void deallocate_buffer(struct file_buffer *buffer)
{
    free(buffer->data);
}

char get_next_char(file_buffer *buffer)
{
    char next_char = buffer->data[buffer->index];

    printf("%d %d\n", buffer->index, buffer->line);

    if (next_char == EOF)
    {
        buffer->index = 0;
        return '\0';
    }

    if (next_char == '\0')
    {
        buffer->index = 0;
        return '\0';
    }

    if (next_char == '\n')
        buffer->line++;

    buffer->index++;

    return buffer->data[buffer->index - 1];
}

void go_back(file_buffer *buffer)
{
    if (buffer->index == 0)
        return;

    char past_char = buffer->data[buffer->index - 1];

    if (past_char == '\n')
        buffer->line--;

    buffer->index--;
}