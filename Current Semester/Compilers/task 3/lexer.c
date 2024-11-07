#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"

const char *const SPECIAL_WORDS[] = {"while", "volatile", "void", "unsigned", "switch", "struct", "static", "sizeof", "signed", "short", "return", "register", "long", "int", "if", "goto", "for", "float", "extern", "enum", "else", "double", "do", "default", "continue", "const", "char", "case", "break", "auto", "less_than", "include", NULL};

typedef enum lexer_state
{
    START,
    READING,
    FINISH
} lexer_state;

const char *const STATE_LABEL[] = {"START", "READING", "FINISH"};

lexem_buffer *allocate_lexem_buffer()
{
    lexem_buffer *new_lexem = (lexem_buffer *)malloc(sizeof(lexem_buffer));

    new_lexem->data = (char *)malloc(sizeof(char) * 65);
    new_lexem->line = 0;
    new_lexem->index = 0;

    return new_lexem;
}

void deallocate_lexem_buffer(lexem_buffer *kill)
{
    free(kill->data);
    free(kill);
}

int is_special(char *string)
{
    int index = 0;

    while (SPECIAL_WORDS[index] != NULL)
        if (strcmp(SPECIAL_WORDS[index++], string) == 1)
            return index;

    return -1;
}

int is_numeric(char character)
{
    return isalnum(character);
}

int is_common_character(char character)
{
    return isalpha(character) || character == '_' || character == '#';
}

void write_character(lexem_buffer *lexem, char character)
{
    sprintf(&lexem->data[lexem->index++], "%c", character);
}

int start_reading(lexem_buffer *lexem, char character)
{
    if (character == '\0')
        return 0;

    if (is_common_character(character) == 0)
        return -1;

    write_character(lexem, character);

    return 1;
}

int read_character(lexem_buffer *lexem, char character)
{
    if (is_common_character(character) == 0)
    {
        write_character(lexem, '\0');
        return 0;
    }

    write_character(lexem, character);
    return 1;
}

int run_lexer_machine_state(file_buffer *buffer, lexem_buffer *lexem, lexer_state *state)
{
    int result, type;

    char character = get_next_char(buffer);

    if (*state == START)
    {
        result = start_reading(lexem, character);

        if (result == 0)
        {
            go_back(buffer);
            return 0;
        }

        if (result == 1)
            *state = READING;
    }

    else if (*state == READING)
    {

        result = read_character(lexem, character);

        if (result == 0)
        {
            go_back(buffer);
            *state = FINISH;
        }
    }

    else if (*state == FINISH)
    {
        type = is_special(lexem->data);

        if (type == -1)
            lexem->token = 0;
        else
            lexem->token = type;

        lexem->line = buffer->line;

        go_back(buffer);

        return 1;
    }

    return -1;
}

void reset_lexem_buffer(lexem_buffer *lexem)
{
    lexem->index = 0;
    memset(lexem->data, '\0', 65);
}

int find_lexem(file_buffer *buffer, lexem_buffer *lexem)
{
    int result;
    lexer_state state = START;

    while (1)
    {
        result = run_lexer_machine_state(buffer, lexem, &state);

        if (result == 0)
            return 0;

        if (result == 1)
            return 1;
    }

    return 0;
}

int get_next_lexem(file_buffer *buffer, lexem_buffer *lexem)
{
    reset_lexem_buffer(lexem);

    do
        if (find_lexem(buffer, lexem))
            return 1;
    while (read_file(buffer));

    return 0;
}