#include <file_buffer.h>

typedef enum lexer
{
    ID,
    WHILE,
    VOLATILE,
    VOID,
    UNSIGNED,
    SWITCH,
    STRUCT,
    STATIC,
    SIZEOF,
    SIGNED,
    SHORT,
    RETURN,
    REGISTER,
    LONG,
    INT,
    IF,
    GOTO,
    FOR,
    FLOAT,
    EXTERN,
    ENUM,
    ELSE,
    DOUBLE,
    DO,
    DEFAULT,
    CONTINUE,
    CONST,
    CHAR,
    CASE,
    BREAK,
    AUTO,
    DOUBLE_EQUAL,
    EQUAL,
    LESS_THAN,
    INCLUDE
} lexer;

typedef struct lexem_buffer
{
    int line;
    int index;
    char *data;
    lexer token;
    char *const token_name;
} lexem_buffer;

lexem_buffer *allocate_lexem_buffer();

void deallocate_lexem_buffer(lexem_buffer *kill);

int get_next_lexem(file_buffer *buffer, lexem_buffer *mylexem);
