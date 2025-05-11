#include <stdio.h>
#include <stdlib.h>
#include <funcs.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
        return 0;

    char const *file_name = argv[1];

    FILE *file = fopen(file_name, "rb");

    if (file == NULL)
        return 0;

    int buffer_size = atoi(argv[2]);

    if (buffer_size == 0)
        return 0;

    struct char_buffer buffer = allocate_buffer(buffer_size);

    replace_print(file, buffer);

    fclose(file);
    deallocate_buffer(buffer);

    return 0;
}
