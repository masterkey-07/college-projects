#ifndef LEXER_H
#define LEXER_H

#include <file_buffer.h>

typedef enum lexer
{
    ID,
    NUM,
    ATTR,
    IF,
    THEN,
    ELSE,
    END,
    REPEAT,
    UNTIL,
    READ,
    WRITE,
    PLUS,
    MINUS,
    MULTI,
    DIV,
    EQUAL,
    LESS,
    GREATER,
    LPAR,
    RPAR,
    SEMICOL
} lexer;

typedef struct lexem_buffer
{
    int line;
    int index;
    lexer token;
    char *data;
} lexem_buffer;

lexem_buffer *allocate_lexem_buffer();

void deallocate_lexem_buffer(lexem_buffer *kill);

int get_next_lexem(file_buffer *buffer, lexem_buffer *mylexem);

char *get_type_label(int type);

#endif