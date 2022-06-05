#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

int get_index(char c)
{
    if (c <= 32)
        return 0;
    else
        return c - 96
}

void counting_sort(string *a, string *b, int n, string k, int d)
{
    int *c = (int *)malloc(sizeof(int) * strlen(k));

    int i;

    for (i = 0; i < k; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
        c[get_index(a[i][d])]++;

    for (i = 1; i < k; i++)
        c[i] += c[i - 1];

    for (i = n - 1; i >= 0; i--)
        b[--c[a[i]]] = a[i];
}

string make_alphabet()
{
    string alphabet = (string)malloc(sizeof(char) * 27);

    int i;

    alphabet[0] = ' ';

    for (i = 1; i < 27; i++)
        alphabet[i] = (char)(96 + i);

    return alphabet;
}

int main(int argc, char const *argv[])
{
    string *strings;

    int length, i, j, word_length = 0, max_word = 0;

    scanf("%d", &length);

    strings = (string *)malloc(sizeof(string) * length);

    for (i = 0; i < length; i++)
    {
        strings[i] = (string)malloc(sizeof(char) * 20);

        scanf("%s", strings[i]);

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

    return 0;
}