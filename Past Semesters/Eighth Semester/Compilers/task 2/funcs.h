#define BUFFER_SIZE sizeof(char) * 256

typedef struct file_buffer
{
    int line;
    int index;
    char *data;
    char past_char;
} file_buffer;

file_buffer *allocate_buffer();

void deallocate_buffer(struct file_buffer *buffer);

char get_next_char(struct file_buffer *buffer);

void go_back(file_buffer *buffer);
