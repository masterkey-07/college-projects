#include <stdio.h>
#include <stdlib.h>

#define BLACK 0
#define RED 1

#define TRUE 1
#define FALSE 0

struct tree
{
    int value;
    int color;
    struct tree *left_node;
    struct tree *right_node;
};

typedef struct tree tree;

tree *left_rotate(tree *father);

tree *right_rotate(tree *father);

tree *create_tree(int value)
{
    tree *output = (tree *)malloc(sizeof(tree));

    output->color = RED;
    output->value = value;
    output->left_node = NULL;
    output->right_node = NULL;

    return output;
}

void change_color(tree *node)
{
    int old_color = node->color;

    int new_color = BLACK;

    if (old_color == BLACK)
        new_color = RED;

    node->color = new_color;

    if (node->left_node != NULL)
        node->left_node->color = old_color;

    if (node->right_node != NULL)
        node->right_node->color = old_color;
}

tree *left_rotate(tree *father)
{
    tree *child = father->right_node;

    if (child->right_node == NULL && child->left_node != NULL)
        child = right_rotate(child);

    father->right_node = child->left_node;
    child->left_node = father;
    return child;
}

tree *right_rotate(tree *father)
{
    tree *child = father->left_node;

    if (child->left_node == NULL && child->right_node != NULL)
        child = left_rotate(child);

    father->left_node = child->right_node;
    child->right_node = father;
    return child;
}

tree *balance_tree(tree *father, tree *node, int change)
{
    int error = FALSE, left_node = TRUE;

    if (node->color == RED)
    {
        if (node->left_node != NULL)
            if (node->left_node->color == RED)
                error = TRUE;

        if (node->right_node != NULL)
            if (node->right_node->color == RED)
                error = TRUE;

        if (father->color == RED)
            error = TRUE;
    }

    if (error)
    {
        printf("\nBEFORE\n");
        print_tree(father, 0);

        if (father->right_node != node)
        {
            if (father->right_node == NULL)
            {
                father = right_rotate(father);
                change_color(father);
            }
            else if (father->color == RED)
            {
                if (change)
                    father = right_rotate(father);
            }
            else
            {
                if (change)
                    father = right_rotate(father);

                change_color(father);
            }
        }
        else
        {
            if (father->left_node == NULL)
            {
                father = left_rotate(father);
                change_color(father);
            }
            else if (father->color == RED)
            {
                if (change)
                    father = left_rotate(father);
            }
            else
            {
                if (change)
                    father = left_rotate(father);
                change_color(father);
            }
        }
    }

    printf("\nAFTER\n");
    print_tree(father, 0);
    printf("\n..............\n");

    return father;
}

tree *insert_tree(tree *father, tree *child, int value)
{
    tree *new_node, *insert_node;

    int old_color;

    if (child == NULL)
    {
        new_node = create_tree(value);

        if (father == NULL)
            new_node->color = BLACK;

        return new_node;
    }
    else if (value < child->value)
        insert_node = child->left_node;
    else
        insert_node = child->right_node;

    if (insert_node != NULL)
        old_color = insert_node->color;

    new_node = insert_tree(child, insert_node, value);

    if (value < child->value)
        child->left_node = new_node;
    else
        child->right_node = new_node;

    if (insert_node == NULL)
        return child;

    if (insert_node == new_node)
        if (old_color != new_node->color)
            child = balance_tree(child, new_node, FALSE);
        else
            child = balance_tree(child, new_node, TRUE);
    else
        child = balance_tree(child, new_node, TRUE);

    if (father == NULL)
        child->color = BLACK;

    return child;
}

tree *get_tree(tree *node, int value)
{
    if (node != NULL)
        if (node->value == value)
            return node;
        else if (value < node->value)
            return get_tree(node->left_node, value);
        else
            return get_tree(node->right_node, value);
    else
        return NULL;
}

int get_height(tree *node)
{
    if (node != NULL)
    {
        int left_height = get_height(node->left_node);

        int right_height = get_height(node->right_node);

        if (left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }

    return 0;
}

void print_tree(tree *node, int level)
{
    int i;
    if (node != NULL)
    {
        print_tree(node->right_node, level + 1);
        for (i = 0; i < level; i++)
            printf("\t");
        printf("%d (%d)\n", node->value, node->color);
        print_tree(node->left_node, level + 1);
    }
}

int main(int argc, char const *argv[])
{
    int value = 0, found;

    tree *node = NULL;

    while (value > -1)
    {
        scanf("%d", &value);

        if (value > -1)
        {
            // printf("\ninserting : %d\n", value);
            node = insert_tree(NULL, node, value);
            // print_tree(node, 0);
            // printf("\n--------\n");
        }
    }

    print_tree(node, 0);
    printf("\n--------\n");

    tree *child;

    value = 0;

    while (value > -1)
    {
        scanf("%d", &value);

        if (value > -1)
        {
            child = get_tree(node, value);
            if (child == NULL)
            {
                printf("\ninserting : %d\n", value);
                node = insert_tree(NULL, node, value);
                print_tree(node, 0);
                printf("\n--------\n");
            }
            // else
            //     printf("found it\n");
        }
    }

    // print_tree(node, 0);
    // printf("\n--------\n");

    scanf("%d", &value);

    return 0;
}
