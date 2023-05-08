#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

int get_index(char c, char *keys)
{
    if (c <= 32)
        return 0;
    else
    {
        int i = 0;

        for (i = 1; i < 27; i++)
        {
            // printf("t : %c == %c\n", c, keys[i - 1]);
            if (keys[i - 1] == c)
                return i;
        }
    }
}

string *counting_sort(string *input, string *output, int length, int keys, int column, char *chars)
{
    int *vector = (int *)malloc(sizeof(int) * keys);

    int index;

    for (index = 0; index < keys; index++)
        vector[index] = 0;

    int letter_index = 0;

    for (index = 0; index < length; index++)
    {
        letter_index = get_index(input[index][column], chars);
        vector[letter_index]++;
    }

    for (index = 0; index < keys; index++)
    {
        vector[index] += vector[index - 1];
        printf("%d ", vector[index]);
    }

    printf("\n");

    for (index = length - 1; index >= 0; index--)
    {
        letter_index = get_index(input[index][column], chars);

        output[--vector[letter_index]] = input[index];
    }

    return output;
}

int main(int argc, char const *argv[])
{
    string *strings;
    string *output;

    int start, number_words, length, i, j, word_length = 0, max_word = 0;

    char keys[27];

    scanf("%d", &length);
    scanf("%s", keys);

    strings = (string *)malloc(sizeof(string) * length);

    for (i = 0; i < length; i++)
    {
        strings[i] = (string)malloc(sizeof(char) * 20);

        scanf("%s", strings[i]);
    }

    for (i = 0; i < length; i++)
    {
        word_length = strlen(strings[i]);

        if (max_word < word_length)
            max_word = word_length;

        for (j = 0; j < word_length; j++)
            if (strings[i][j] < 97)
                strings[i][j] += 32;

        printf("%s.\n", strings[i]);

        for (j = word_length; j < 20; j++)
            strings[i][j] = ' ';
    }

    printf("%d\n", max_word);

    for (i = max_word - 1; i >= 0; i--)
    {
        output = (string *)malloc(sizeof(string) * length);
        strings = counting_sort(strings, output, length, 27, i, keys);
    }

    for (i = 0; i < length; i++)
    {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    free(output);

    return 0;
}