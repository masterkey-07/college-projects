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

tree *remove_tree(tree *node, int value, int *found);

tree *create_tree(int value)
{
    tree *node = (tree *)malloc(sizeof(tree));

    node->left_node = NULL;
    node->right_node = NULL;
    node->balance = 0;
    node->value = value;

    return node;
}

tree *balance_tree(tree *father)
{
    tree *child, *grand_child;

    if (father->balance == 2)
    {
        child = father->left_node;

        if (child->balance >= 0)
        {
            father->left_node = child->right_node;
            child->right_node = father;

            child->balance = 0;

            father->balance = 0;

            if (father->left_node != NULL)
                father->balance++;

            if (father->right_node != NULL)
                father->balance--;

            if (father->balance != 0)
                child->balance--;

            return child;
        }
        else
        {
            grand_child = child->right_node;
            child->right_node = grand_child->left_node;
            grand_child->left_node = child;
            father->left_node = grand_child->right_node;
            grand_child->right_node = father;

            father->balance = 0;
            child->balance = 0;

            if (grand_child->balance == 1)
                father->balance = -1;
            else if (grand_child->balance == -1)
                child->balance = 1;

            grand_child->balance = 0;

            return grand_child;
        }
    }
    else
    {
        child = father->right_node;

        if (child->balance <= 0)
        {
            father->right_node = child->left_node;
            child->left_node = father;

            child->balance = 0;

            father->balance = 0;

            if (father->left_node != NULL)
                father->balance++;

            if (father->right_node != NULL)
                father->balance--;

            if (father->balance != 0)
                child->balance++;

            return child;
        }
        else
        {
            grand_child = child->left_node;
            child->left_node = grand_child->right_node;
            grand_child->right_node = child;
            father->right_node = grand_child->left_node;
            grand_child->left_node = father;

            father->balance = 0;
            child->balance = 0;

            if (grand_child->balance == 1)
                child->balance = -1;
            else if (grand_child->balance == -1)
                father->balance = 1;

            grand_child->balance = 0;

            return grand_child;
        }
    }
}

tree *remove_node(tree *node)
{
    tree *child, *father;

    int found, old_balance;

    if (node->left_node == NULL && node->right_node == NULL)
    {
        free(node);
        node = NULL;
    }
    else if (node->left_node == NULL)
    {
        child = node;
        node = node->right_node;
        free(child);
    }
    else if (node->right_node == NULL)
    {
        child = node;
        node = node->left_node;
        free(child);
    }
    else
    {
        father = node;
        child = node->right_node;

        while (child->left_node != NULL)
        {
            father = child;
            child = child->left_node;
        }

        node->value = child->value;

        if (father == node)
        {
            father->right_node = child->right_node;

            father->balance++;
        }
        else
        {
            old_balance = node->right_node->balance;
            node->right_node = remove_tree(node->right_node, node->value, &found);

            if (abs(old_balance) > abs(node->right_node->balance))
                node->balance++;
        }

        if (abs(node->balance) == 2)
            node = balance_tree(node);
    }

    return node;
}

tree *remove_tree(tree *node, int value, int *found)
{
    int old_balance, left = 0;

    tree *remove_child = NULL, *new_child;

    if (node != NULL)
    {
        if (node->value == value)
        {
            *found = 1;
            return remove_node(node);
        }
        else if (value < node->value)
        {
            remove_child = node->left_node;

            if (remove_child != NULL)
                old_balance = remove_child->balance;

            left = 1;
        }
        else
        {
            remove_child = node->right_node;

            if (remove_child != NULL)
                old_balance = remove_child->balance;
        }

        new_child = remove_tree(remove_child, value, found);

        if (remove_child != NULL)
        {
            if (new_child == NULL)
                if (left == 1)
                    node->balance--;
                else
                    node->balance++;
            else if (abs(old_balance) > abs(new_child->balance))
                if (left == 1)
                    node->balance--;
                else
                    node->balance++;

            if (left == 1)
                node->left_node = new_child;
            else
                node->right_node = new_child;

            if (abs(node->balance) == 2)
                node = balance_tree(node);
        }
    }

    return node;
}

tree *insert_tree(tree *node, int value)
{
    tree *new_node, *insert_node;

    int balance = 0, old_balance;

    if (node == NULL)
        return create_tree(value);
    else if (value < node->value)
    {
        balance = 1;
        insert_node = node->left_node;
    }
    else
    {
        balance = -1;
        insert_node = node->right_node;
    }

    if (insert_node != NULL)
        old_balance = insert_node->balance;

    new_node = insert_tree(insert_node, value);

    if (balance > 0)
        node->left_node = new_node;
    else
        node->right_node = new_node;

    if (insert_node != NULL)
        if (new_node->balance == 0 || new_node->balance == old_balance)
            balance = 0;
        else if (abs(old_balance) > abs(new_node->balance))
            balance = -balance;

    node->balance += balance;

    if (abs(node->balance) == 2)
        node = balance_tree(node);

    return node;
}

void free_tree(tree *node)
{
    if (node != NULL)
    {
        free_tree(node->left_node);
        free_tree(node->right_node);
        free(node);
    }
}

int get_height(tree *node)
{
    int height = 0;

    if (node != NULL)
        if (node->balance >= 0)
            return 1 + get_height(node->left_node);
        else
            return 1 + get_height(node->right_node);
    else
        return 0;
}

tree *get_node(tree *node, int value)
{

    if (node != NULL)
    {
        if (node->value == value)
            return node;
        else if (value < node->value)
            return get_node(node->left_node, value);
        else
            return get_node(node->right_node, value);
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    int value = 0, found;

    tree *node = NULL;

    while (value > -1)
    {
        scanf("%d", &value);

        if (value > -1)
            node = insert_tree(node, value);
    }

    value = 0;

    printf("%d, %d, %d\n", get_height(node) - 1, get_height(node->left_node), get_height(node->right_node));

    while (value > -1)
    {
        scanf("%d", &value);

        if (value > -1)
        {
            found = 0;

            node = remove_tree(node, value, &found);

            if (found == 0)
                node = insert_tree(node, value);
        }
    }

    scanf("%d", &value);

    tree *result = get_node(node, value);

    if (result != NULL)
        printf("%d, %d, %d", get_height(result) - 1, get_height(result->left_node), get_height(result->right_node));
    else
        printf("Valor nao encontrado");

    free_tree(node);

    return 0;
}
