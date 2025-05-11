struct char_buffer
{
    int size;
    char *data;
};

void deallocate_buffer(struct char_buffer buffer);
void replace_print(FILE *file, struct char_buffer bf);
struct char_buffer allocate_buffer(int buffer_size);
