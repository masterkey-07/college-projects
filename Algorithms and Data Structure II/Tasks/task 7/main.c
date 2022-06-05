#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

int get_index(char c)
{
    if (c <= 32)
        return 0;
    else
        return c - 96;
}

string *counting_sort(string *a, string *b, int n, int k, int d)
{
    int *c = (int *)malloc(sizeof(int) * k);

    int i;

    for (i = 0; i < k; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
        c[get_index(a[i][d])]++;

    for (i = 0; i < k; i++)
    {
        c[i] += c[i - 1];
        printf("%d ", c[i]);
    }

    printf("\n");

    for (i = n - 1; i >= 0; i--)
        b[--c[get_index(a[i][d])]] = a[i];

    return b;
}

int main(int argc, char const *argv[])
{
    string *strings;
    string *output;

    int start, number_words, length, i, j, word_length = 0, max_word = 0;

    scanf("%d", &length);

    strings = (string *)malloc(sizeof(string) * length);

    for (i = 0; i < length; i++)
    {
        strings[i] = (string)malloc(sizeof(char) * 20);

        scanf("%s", strings[i]);
    }

    scanf("%d", &start);
    scanf("%d", &number_words);

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
        strings = counting_sort(strings, output, length, 27, i);
    }

    for (i = start - 1; i < start + number_words - 1; i++)
    {
        printf("%s\n", strings[i]);
        free(strings[i]);
        free(output[i]);
    }

    return 0;
}