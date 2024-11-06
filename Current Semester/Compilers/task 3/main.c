#include <stdio.h>
#include <funcs.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 0;

    char const *file_name = argv[1];

    char c;

    FILE *file = fopen(file_name, "rb");

    if (file == NULL)
        return 0;

    file_buffer *buffer = allocate_buffer();

    int count = 0;

    while (fgets(buffer->data, 256, file))
    {
        printf("%s\n", buffer->data);

        while ((c = get_next_char(buffer)) != '\0')
        {
            count++;

            printf("trying: %c\n", c);

            if (count > 10)
            {
                count = 0;
                go_back(buffer);
            }
            else
                printf("gotcha: %c\n", c);
        }
    }

    deallocate_buffer(buffer);

    fclose(file);

    return 0;
}
