/* Informações
    - Victor Jorge Carvalho Chaves
    - RA: 156.740
    -Turma: Noturno NB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    void *data;
    int type;
    struct Node *leftTree;
    struct Node *rightTree;
} Tree;

typedef Tree *PTree;

#define SymbolTreeType 0
#define NumberTreeType 1

#define True 0
#define False 1

PTree allocateTree()
{
    // Aloca espaço na memória para a arvore binária
    return (PTree)malloc(sizeof(Tree));
}

// Printa a arvore binario na forma horizontal
void printTree(PTree node, int level)
{
    int i;
    if (node != NULL)
    {
        if (node->type != NumberTreeType)
        {
            for (i = 0; i < level + 1; i++)
                printf("\t");
            printf("%d\n", node->leftTree->data);
            for (i = 0; i < level; i++)
                printf("\t");
            printf("%c\n", node->data);

            printTree(node->rightTree, level + 1);
        }
        else
        {
            for (i = 0; i < level; i++)
                printf("\t");
            printf("%d\n", node->data);
        }
    }
}

// Funcao para verificar se o char é um numero ou não
int verifyNumber(char number)
{
    if (number >= 48 && number <= 57)
        return True;
    else
        return False;
}

// Pega a posição do *char e converte essa posição para numero
int getNumber(char *string, int start, int end)
{
    int i;
    int result = 0;

    for (i = start; i <= end; i++)
        result += (((int)string[i]) - 48) * pow(10, end - i);

    if (result > 100)
        result++;

    return result;
}

// Acha o primeiro numero de tras para frente do *char a partir do index passado
int findNumber(char *equation, int *index)
{
    int startNumber = 0;
    int endNumber = -1;
    int i;

    for (i = *index; i >= 0; i--)
        if (verifyNumber(equation[i]) == True && endNumber == -1)
            endNumber = i;
        else if (verifyNumber(equation[i]) == False && endNumber != -1 && startNumber == 0)
            startNumber = i + 1;

    if (endNumber == -1)
        return NULL;
    else
    {
        *index = startNumber - 1;
        return getNumber(equation, startNumber, endNumber);
    }
}

// Acha o primeiro simbolo de tras para frente do *char a partir do index passado
char findSymbol(char *equation, int *index)
{
    int i;

    if (*index < 0)
        return NULL;

    for (i = *index; i >= 0; i--)
        if (verifyNumber(equation[i]) == True)
            return NULL;
        else if (equation[i] == '+')
        {
            *index = i - 1;
            return '+';
        }
        else if (equation[i] == '-')
        {
            *index = i - 1;
            return '-';
        }
}

// Cria uma arvore sem filhos apenas com um numero
PTree createNumberTreeType(int value)
{
    PTree tree = allocateTree();

    tree->data = value;
    tree->leftTree = NULL;
    tree->rightTree = NULL;
    tree->type = NumberTreeType;

    return tree;
}

// Converte uma equacao em uma arvore binaria atraves de recursividade
PTree readEquation(char *equation, int *index)
{
    char symbol;
    int leftNumber;

    PTree tree = allocateTree();

    tree->type = SymbolTreeType;

    leftNumber = findNumber(equation, index);

    symbol = findSymbol(equation, index);

    if (symbol == NULL)
    {
        free(tree);
        return createNumberTreeType(leftNumber);
    }
    tree->leftTree = createNumberTreeType(leftNumber);

    tree->data = symbol;

    tree->rightTree = readEquation(equation, index);

    return tree;
}

// Realiza o calculo da equacao pela arvore binaria
int calculateEquation(PTree tree)
{
    if (tree->type == NumberTreeType)
        return tree->data;
    else if (tree->data == '+')
        return (int)tree->leftTree->data + calculateEquation(tree->rightTree);
    else
        return calculateEquation(tree->rightTree) - (int)tree->leftTree->data;
}

void freeTree(PTree tree)
{
    if (tree != NULL)
    {
        free(tree->leftTree);
        free(tree->rightTree);
        free(tree);
    }
}

// Verifica se a equacao esta correta
int verifyEquation(char *equation, int end)
{
    int i;
    int isSpace = False;
    int isSymbol = False;
    int isNumber = False;
    for (i = 0; i <= end; i++)
        if (verifyNumber(equation[i]) == True)
        {
            if (isSpace == True && isNumber == True)
                return False;
            isNumber = True;
            isSymbol = False;
            isSpace = False;
        }
        else if (equation[i] == '+' || equation[i] == '-')
        {
            if ((isSpace == True && isSymbol == True) || isNumber == False)
                return False;
            isSymbol = True;
            isSpace = False;
            isNumber = False;
        }
        else
        {
            isSpace = True;
        }

    return True;
}

int main()
{
    char equation[500];

    printf("Digite a expressao: ");

    scanf("%[^\n]%*c", equation);

    int search = True;

    int *length = (int *)malloc(sizeof(int)), i = -1;

    while (search == True)
        if (equation[++i] == '\0')
        {
            search = False;
            *length = i - 1;
        }

    if (verifyEquation(equation, *length) == True)
    {

        PTree result = readEquation(equation, length);

        printTree(result, 0);

        printf("\nA solucao da expressao eh %d\n", calculateEquation(result));

        freeTree(result);
    }
    else
        printf("\nA expressao esta incorreta\n");

    free(length);
    return 0;
}
