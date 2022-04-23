/*
Aluno: Victor Jorge Carvalho Chaves
R.A: 156.740
Turma: NB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER 0
#define FALSE 1
#define TRUE 0
#define OPERATOR 1
#define SPACE -1

struct Stack
{
    int top;
    struct Data *data;
};

struct Data
{
    char *value;
};

struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->data = (struct Data *)malloc(sizeof(struct Data));
    stack->top = -1;
}

void push(struct Stack *stack, char *value)
{
    stack->data = (struct Data *)realloc(stack->data, sizeof(struct Data) * (++stack->top + 1));
    (stack->data + stack->top)->value = value;
}

char *pop(struct Stack *stack)
{
    if (stack->top > -1)
    {
        char *value = (stack->data + stack->top)->value;
        stack->data = (struct Data *)realloc(stack->data, sizeof(struct Data) * (--stack->top + 1));
        return value;
    }
    else
    {
        stack->top == -1;
        return NULL;
    }
}

int verifyType(char value)
{
    if (value == '0' || value == '1' || value == '2' || value == '3' || value == '4' || value == '5' || value == '6' || value == '7' || value == '8' || value == '9')
        return NUMBER;
    else if (value == ' ')
        return SPACE;
    else if (value == '+' || value == '-' || value == '/' || value == '*' || value == '^')
        return OPERATOR;
    else
        return -10;
}

int hasPriority(char value, char value2)
{
    if (value == '^' && value2 != '^')
        return TRUE;
    else if ((value == '/' || value == '*') && (value2 != '^' && value2 != '/' && value2 != '*'))
        return TRUE;
    else
        return FALSE;
}

int calculate(int a, int b, char operation)
{
    if (operation == '+')
        return a + b;
    else if (operation == '-')
        return a - b;

    else if (operation == '*')

        return a * b;
    else if (operation == '/')
        return a / b;

    else if (operation == '^')
        return pow(a, b);

    return 0;
}

int convertToInt(char *value, int ini, int end)
{
    int i;
    int result = 0;
    if (end - ini > 1)
        for (i = ini; i < end; i++)
            result += (((int)value[i]) - 48) * pow(10, end - i - 1);
    else
    {
        result = ((int)((char)value)) - 48;
        return result;
    }
    return result;
}

int convertToPosFix(char *expression)
{
    int i = -1, j = 0, result;
    char posFix[100], value, value2;
    struct Stack *stack = createStack();
    int wasOperator = FALSE;
    int wasSpace = FALSE;

    while (expression[++i] != '\0')
    {
        value = expression[i];

        result = verifyType(value);
        if (result == NUMBER)
        {
            if (wasSpace == TRUE && wasOperator == FALSE)
            {
                free(stack);
                return NULL;
            }

            if (wasOperator == TRUE)
                posFix[j++] = ' ';

            posFix[j++] = value;

            wasOperator = FALSE;
            wasSpace = FALSE;
        }
        else if (result == OPERATOR)
        {
            wasOperator = TRUE;
            wasSpace = FALSE;
            value2 = (char)pop(stack);

            if (value2)
                if (hasPriority(value, value2) == TRUE)
                {
                    push(stack, (char *)value2);
                    push(stack, (char *)value);
                }
                else
                {
                    posFix[j++] = ' ';
                    while (hasPriority(value, value2) == FALSE)
                    {
                        posFix[j++] = value2;
                        value2 = (char)pop(stack);
                        if (value2 == NULL)
                            break;
                        posFix[j++] = ' ';
                    }

                    if (value2 != NULL)
                        push(stack, (char *)value2);

                    push(stack, (char *)value);
                }
            else
                push(stack, (char *)value);
        }
        else if (result == SPACE)
        {
            wasSpace = TRUE;
            continue;
        }
        else
        {
            free(stack);
            return NULL;
        }
    }
    posFix[j++] = ' ';

    while (TRUE == TRUE)
    {
        value = pop(stack);
        if (value == NULL)
            break;

        posFix[j++] = value;
        posFix[j++] = ' ';
    }

    int k, a, b, wasNumber = FALSE;

    for (i = 0; i < j; i++)
    {
        value = posFix[i];
        printf("%c", value);
        result = verifyType(value);

        if (result == NUMBER)
        {
            if (wasNumber == TRUE)
                continue;

            if (verifyType(posFix[i + 1]) != NUMBER)
            {
                result = convertToInt(value, 0, 1);
                push(stack, (char *)result);
            }
            else
            {
                k = i + 1;
                while (verifyType(posFix[++k]) == NUMBER)
                    continue;

                result = convertToInt(posFix, i, k);
                push(stack, (char *)result);
            }
            wasNumber = TRUE;
        }
        else if (result == OPERATOR)
        {
            wasNumber = FALSE;
            b = (int)pop(stack);
            a = (int)pop(stack);
            push(stack, (char *)calculate(a, b, value));
        }
        else
        {
            wasNumber = FALSE;
            continue;
        }
    }

    result = (int)pop(stack);

    free(stack);

    return result;
}

int main()
{
    char arithmeticExpression[100];

    int result;

    printf("Escreva a conta a ser calculada: ");
    scanf("%[^\n]s", arithmeticExpression);

    printf("Forma posfixa : ");

    result = convertToPosFix(arithmeticExpression);

    if (result != NULL)
        printf("\nResultado da conta: %d\n", result);
    else
        printf("\nFoi inserido uma equacao incorreta\n");

    return 0;
}
