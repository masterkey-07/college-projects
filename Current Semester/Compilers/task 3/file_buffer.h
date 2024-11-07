#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE sizeof(char) * 256

typedef struct file_buffer
{
    int line;
    int index;
    FILE *file;
    char *data;
} file_buffer;

file_buffer *allocate_buffer(FILE *file);

void deallocate_buffer(struct file_buffer *buffer);

char get_next_char(struct file_buffer *buffer);

void go_back(file_buffer *buffer);

char *read_file(file_buffer *buffer);
