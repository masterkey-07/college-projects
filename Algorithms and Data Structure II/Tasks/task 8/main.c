#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct tree
{
    int value;
    int balance;
    struct tree *left_node;
    struct tree *right_node;
};

typedef struct tree tree;

tree *create_tree(int value)
{
    tree *node = (tree *)malloc(sizeof(tree));

    node->left_node = NULL;
    node->right_node = NULL;
    node->balance = 0;
    node->value = value;

    return node;
}

int insert_tree(tree *node, int value)
{
    int result;

    if (node->value < value)
    {
        if (node->left_node == NULL)
        {
            node->left_node = create_tree(value);
            node->balance++;

            if (node->right_node == NULL)
                return 1;
            else
                return 0;
        }
        else
        {
            node->balance++;

            result = insert_tree(node->left_node, value);

            if (result == 0)
                node->balance--;
        }
    }
    else
    {
        if (node->right_node == NULL)
        {
            node->right_node = create_tree(value);
            node->balance--;

            if (node->left_node == NULL)
                return 1;
            else
                return 0;
        }
        else
        {
            node->balance--;

            result = insert_tree(node->right_node, value);

            if (result == 0)
                node->balance++;
        }
    }

    if (abs(node->balance) >= 2)
    {
    }

    return result;
}

void print_tree(tree *node, int level)
{
    // Printa a arvore binario na forma horizontal
    if (node != NULL)
    {
        int i;
        print_tree(node->left_node, level + 1);
        for (i = 0; i < level; i++)
            printf("\t");
        printf("%d (%d)\n", node->value, node->balance);
        print_tree(node->right_node, level + 1);
    }
}

int main(int argc, char const *argv[])
{
    int n;

    scanf("%d", &n);

    tree *node = create_tree(n);

    while (n > -1)
    {
        scanf("%d", &n);

        if (n > -1)
            insert_tree(node, n);
    }

    print_tree(node, 0);

    return 0;
}
