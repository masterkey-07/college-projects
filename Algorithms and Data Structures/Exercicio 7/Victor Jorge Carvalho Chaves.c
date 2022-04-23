/* Informações
    - Victor Jorge Carvalho Chaves
    - RA: 156.740
    -Turma: Noturno NB */

#include <stdio.h>
#include <stdlib.h>

typedef struct TypeTree
{
    char name;
    struct TypeTree *leftTree;
    struct TypeTree *rightTree;
} Tree;

typedef Tree *PTree;

PTree allocateTree()
{
    // Aloca espaço na memória para a arvore binária
    return (PTree)malloc(sizeof(Tree));
}

void printTree(PTree node, int level)
{
    // Printa a arvore binario na forma horizontal
    if (node != NULL)
    {
        int i;
        printTree(node->leftTree, level + 1);
        for (i = 0; i < level; i++)
            printf("\t");
        printf("%c\n", node->name);
        printTree(node->rightTree, level + 1);
    }
}

int findMainPosition(char *prefixTree, char *infixTree, int start, int end, int *indexPosition)
{
    // Encontra a posição do próximo nódulo para ser adicionado na arvore
    // no vetor infixo se baseando no vetor prefixo
    int i;

    for (i = start; i <= end; i++)
        if (infixTree[i] == prefixTree[*indexPosition])
            return i;
}

PTree readNode(char *prefixTree, char *infixTree, int start, int end, int *indexPosition)
{
    // Cria novo nódulo
    PTree node = allocateTree();

    *indexPosition = *indexPosition + 1;

    // Encontra a posição do nódulo que será adicionado na arvore
    int mainPosition = findMainPosition(prefixTree, infixTree, start, end, indexPosition);

    // Seleciona o nome do módulo
    node->name = infixTree[mainPosition];

    // Verifica se há um outro nódulo a esquerda
    if (start == mainPosition)
        // Define como sem nódulo esquerdo
        node->leftTree = NULL;
    else
        // Se haver nódulo, procure o próximo nódulo porém sua área de busca é mudada
        // Assim lendo apenas aqueles a esquerda do nódulo que não foram lidos
        node->leftTree = readNode(prefixTree, infixTree, start, mainPosition - 1, indexPosition);

    // Verifica se há um outro nódulo a direita
    if (end == mainPosition)
        // Define como sem nódulo direito
        node->rightTree = NULL;
    else
        // Se haver nódulo, procure o próximo nódulo porém sua área de busca é mudada
        // Assim lendo apenas aqueles a direita do nódulo que não foram lidos
        node->rightTree = readNode(prefixTree, infixTree, mainPosition + 1, end, indexPosition);

    return node;
}

// Função para liberar espaço no nódulo com recursividade
void freeTree(PTree node)
{
    if (node != NULL)
    {
        freeTree(node->leftTree);
        freeTree(node->rightTree);
        free(node);
    }
}

int main()
{
    int numberOfNodes;
    printf("Digite a quantidade de nos da arvore: ");
    scanf("%d", &numberOfNodes);
    char prefixTree[numberOfNodes], infixTree[numberOfNodes];
    printf("Digite a sequencia dos nos em ordem pre-fixa: ");
    scanf("%s", prefixTree);
    printf("Digite a sequencia dos nos em ordem infixa: ");
    scanf("%s", infixTree);

    int index = -1;

    PTree tree = readNode(prefixTree, infixTree, 0, numberOfNodes - 1, &index);

    printTree(tree, 0);

    freeTree(tree);

    return 0;
}