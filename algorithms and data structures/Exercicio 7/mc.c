#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char info;
    struct Node *left_node;
    struct Node *right_node;

} TNode;
typedef TNode *PNode;

typedef struct Tree
{
    char *prefix;
    char *infix;
    struct Node *root_node;
    int length;
    int index;

} TTree;
typedef TTree *PTree;

void free_node(PNode node)
{
    if (node != NULL)
    {
        free_node(node->left_node);
        free_node(node->right_node);
        free(node);
    }
}

void print_node(PNode node, int level)
{
    if (node != NULL)
    {
        int index;
        print_node(node->left_node, level + 1);

        for (index = 0; index < level; index++)
            printf("\t");

        printf("%c\n", node->info);

        print_node(node->right_node, level + 1);
    }
}

int get_main_node_position(PTree tree, int start, int end)
{
    int index;

    for (index = start; index <= end; index++)
        if (tree->infix[index] == tree->prefix[tree->index])
            return index;
}

PNode make_binary_tree(PTree tree, int start, int end)
{
    PNode new_node = (PNode)malloc(sizeof(TNode));

    tree->index++;

    int main_position = get_main_node_position(tree, start, end);

    new_node->info = tree->infix[main_position];

    if (main_position == start)
        new_node->left_node = NULL;
    else
        new_node->left_node = make_binary_tree(tree, start, main_position - 1);

    if (main_position == end)
        new_node->right_node = NULL;
    else
        new_node->right_node = make_binary_tree(tree, main_position + 1, end);

    return new_node;
}

int main()
{
    PTree tree = (PTree)malloc(sizeof(TTree));

    printf("Digite a quantidade de nos da arvore:");
    scanf("%d", &tree->length);

    tree->prefix = (char *)malloc(sizeof(char) * tree->length);
    tree->infix = (char *)malloc(sizeof(char) * tree->length);

    printf("Digite a sequencia dos nos em ordem pre-fixa: ");
    scanf("%s", tree->prefix);

    printf("Digite a sequencia dos nos em ordem infixa: ");
    scanf("%s", tree->infix);

    tree->index = -1;

    tree->root_node = make_binary_tree(tree, 0, tree->length - 1);

    print_node(tree->root_node, 0);

    free_node(tree->root_node);
    free(tree);

    return 0;
}
