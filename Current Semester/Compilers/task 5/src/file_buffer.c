#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "file_buffer.h"

struct file_buffer *allocate_buffer(FILE *file)
{
    file_buffer *new_buffer = (file_buffer *)malloc(sizeof(file_buffer));

    new_buffer->line = 1;
    new_buffer->index = 0;
    new_buffer->file = file;

    new_buffer->data = (char *)malloc(BUFFER_SIZE);

    memset(new_buffer->data, '\0', BUFFER_SIZE);

    return new_buffer;
}

void deallocate_buffer(struct file_buffer *buffer)
{
    free(buffer->data);
    free(buffer);
}

char *read_file(file_buffer *buffer)
{
    buffer->index = 0;

    return fgets(buffer->data, 256, buffer->file);
}

char get_next_char(file_buffer *buffer)
{
    char next_char = buffer->data[buffer->index];

    if (next_char == EOF)
        return EOF;

    buffer->index++;

    if (next_char == '\0')
        return '\0';

    if (next_char == '\n')
        buffer->line++;

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