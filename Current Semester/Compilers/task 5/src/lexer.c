#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"

char *const SPECIAL_WORDS[] = {"0", "0", "0", "if", "then", "else", "end", "repeat", "until", "read", "write", "+", "-", "*", "/", "=", "<", ">", "(", ")", ";"};

typedef enum lexer_state
{
    START,
    DONE,
    INID,
    INNUM,
    INASSIGN,
    INCOMMENT
} lexer_state;

lexem_buffer *allocate_lexem_buffer()
{
    lexem_buffer *new_lexem = (lexem_buffer *)malloc(sizeof(lexem_buffer));

    new_lexem->line = 0;
    new_lexem->index = 0;
    new_lexem->data = (char *)malloc(sizeof(char) * 65);

    return new_lexem;
}

void deallocate_lexem_buffer(lexem_buffer *kill)
{
    free(kill->data);
    free(kill);
}

int get_token(char *string)
{
    int index = 0;

    while (SPECIAL_WORDS[index] != NULL)
        if (strcmp(SPECIAL_WORDS[index++], string) == 0)
            return index - 1;

    return -1;
}

int is_numeric(char character)
{
    return isalnum(character);
}

int is_common_character(char character)
{
    return isalpha(character) || is_numeric(character) || character == '.' || character == '_' || character == '#';
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

    switch (*state)
    {

    case START:
        if (character == ' ')
            break;

        if (character == '{')
        {
            *state = INCOMMENT;
            break;
        }

        break;
    case DONE:

        break;
    case INCOMMENT:
        if (character == '}')
            *state = START;
        else
            break;

        break;
    case INNUM:
        break;
    case INID:
        break;
    case INASSIGN:
        break;

    default:
        break;
    }

    return -1;

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
            *state = DONE;
        }
    }

    else if (*state == DONE)
    {
        lexem->token = get_token(lexem->data);

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

        if (result == 0 || result == 1)
            return result;
    }

    return 0;
}

int get_next_lexem(file_buffer *buffer, lexem_buffer *lexem)
{
    reset_lexem_buffer(lexem);

    do
        if (find_lexem(buffer, lexem) == 1)
            return 1;
    while (read_file(buffer));

    return 0;
}

char *get_type_label(int type)
{
    return SPECIAL_WORDS[type];
}
