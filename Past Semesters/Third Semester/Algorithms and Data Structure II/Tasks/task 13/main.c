#include <stdio.h>
#include <stdlib.h>

#define M 2
#define MM 4

struct tree
{
    int items[MM];
    struct tree *brother;
    struct tree *children;
    int quantity;
};

typedef struct tree tree;

tree *create_tree()
{
    tree *node = (tree *)malloc(sizeof(tree));

    node->brother = NULL;
    node->children = NULL;
    node->quantity = 0;

    return node;
}

int last_item(tree *node)
{
    return node->items[node->quantity - 1];
}

void insert_sort(tree *node, int item)
{
    int i, value;

    node->quantity++;

    node->items[node->quantity - 1] = item;

    for (i = node->quantity - 1; i > 0; i--)
        if (node->items[i - 1] > node->items[i])
        {
            value = node->items[i];
            node->items[i] = node->items[i - 1];
            node->items[i - 1] = value;
        }
}

int insert_item(tree *node, int item)
{
    if (node->quantity == 0)
    {
        node->items[0] = item;
        node->quantity++;
    }
    else if (node->quantity == MM)
    {
        tree *brother = create_tree();
        int i, output;

        if (node->items[M] < item)
        {
            for (i = M + 1; i < MM; i++)
            {
                brother->items[i - M - 1] = node->items[i];
                node->items[i] = NULL;
                brother->quantity++;
                node->quantity--;
            }

            insert_sort(brother, item);
        }
        else
        {
            for (i = 0; i < M; i++)
            {
                brother->items[i] = node->items[M + i];
                node->items[M + i] = NULL;
                brother->quantity++;
                node->quantity--;
            }

            insert_sort(node, item);
        }

        brother->brother = node->brother;

        node->brother = brother;

        output = last_item(node);

        node->items[node->quantity - 1] = NULL;

        node->quantity--;

        return output;
    }
    else
        insert_sort(node, item);

    return -1;
}

int *insert_tree(tree *node, int item)
{
    int i, output = -1;
    tree *child;

    if (node->children != NULL)
    {
        child = node->children;

        for (i = 0; i < node->quantity; i++)
            if (node->items[i] > item)
                break;
            else
                child = child->brother;

        output = insert_tree(child, item);
        if (output > -1)
        {
            output = insert_item(node, output);

            if (output > -1)
            {
                child = node->children;

                for (i = 0; i < M; i++)
                    child = child->brother;

                node->brother->children = child->brother;

                child->brother = NULL;
            }
        }
    }
    else
        output = insert_item(node, item);

    return output;
}

tree *get_node(tree *node, int item)
{
    int i;
    tree *child = NULL;

    if (node == NULL)
        return NULL;

    child = node->children;

    for (i = 0; i < node->quantity; i++)
        if (node->items[i] == item)
            return node;
        else if (node->items[i] > item)
            break;
        else if (child != NULL)
            child = child->brother;

    return get_node(child, item);
}

int main(int argc, char const *argv[])
{
    int item = 0;
    int i;

    tree *node = create_tree(), *father;

    while (1)
    {
        scanf("%d", &item);

        if (item == -1)
            break;

        item = insert_tree(node, item);

        if (item > -1)
        {
            father = create_tree();
            father->items[0] = item;
            father->children = node;
            father->quantity++;
            node = father;
            father = NULL;
        }
    }
    scanf("%d", &item);

    printf("%d\n", node->quantity);

    node = get_node(node, item);

    if (node != NULL)
        printf("%d\n", node->quantity);
    else
        printf("Valor nao encontrado\n");

    return 0;
}
