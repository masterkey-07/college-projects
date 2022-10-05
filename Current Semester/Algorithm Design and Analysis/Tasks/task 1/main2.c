#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

struct Location
{
    int x;
    int y;
};

typedef struct Location Location;

struct Region
{
    int id, quantity, *map;
    Location location;
    struct List *relations;
};

typedef struct Region Region;

Region *readRegion(int index, int length)
{
    Region *region = (Region *)malloc(sizeof(Region));

    region->map = (int *)malloc(sizeof(int) * length);

    region->map[index] = FALSE;

    region->id = index;

    scanf("%d", &region->location.x);
    scanf("%d", &region->location.y);
    scanf("%d", &region->quantity);

    return region;
}

struct List
{
    Region *item;
    struct List *next;
};

typedef struct List List;

List *push(List *list, Region *item)
{
    List *newList = (List *)malloc(sizeof(List));

    newList->next = list;
    newList->item = item;

    return newList;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void relate(Region *regionA, Region *regionB, int size)
{
    int x = abs(regionA->location.x - regionB->location.x);
    int y = abs(regionA->location.y - regionB->location.y);

    int value = max(x, y);

    size *= 2;

    if (value <= size)
    {
        regionA->relations = push(regionA->relations, regionB);
        regionB->relations = push(regionB->relations, regionA);
        regionA->map[regionB->id] = TRUE;
        regionB->map[regionA->id] = TRUE;
    }
    else
    {
        regionA->map[regionB->id] = FALSE;
        regionB->map[regionA->id] = FALSE;
    }
}

int setSize(int value, int d)
{
    if (value - d > 0)
        return value - d;
    else
        return 0;
}

void resolve(Region *region, Location *location, int *quantity, int d)
{
    int x = region->location.x;
    int y = region->location.y;
    int counter = region->quantity;

    location->x = setSize(x, d);
    location->y = setSize(y, d);
    *quantity = counter;

    List *selected = region->relations;

    while (selected != NULL)
    {
        counter = region->quantity + selected->item->quantity;

        x = max(x, selected->item->location.x);
        y = max(y, selected->item->location.y);

        List *selected2 = selected->item->relations;

        while (selected2 != NULL)
        {
            if (selected2->item->map[region->id] == TRUE)
            {
                x = max(x, selected2->item->location.x);
                y = max(y, selected2->item->location.y);

                counter += selected2->item->quantity;
            }

            selected2 = selected2->next;
        }

        if (*quantity < counter)
        {
            location->x = setSize(x, d);
            location->y = setSize(y, d);
            *quantity = counter;
        }

        selected = selected->next;
    }
}

int main(int argc, char const *argv[])
{
    int test_size, number_points, i, j;

    scanf("%d", &test_size);
    scanf("%d", &number_points);

    Region **regions = (Region **)malloc(sizeof(Region *) * number_points);

    for (i = 0; i < number_points; i++)
    {
        Region *newRegion = readRegion(i, number_points);

        for (j = 0; j < i; j++)
            relate(regions[j], newRegion, test_size);

        regions[i] = newRegion;
    }

    Location location, output;

    output.x = 0;
    output.y = 0;

    int quantity = 0, outputQuantity = 0;

    for (i = 0; i < number_points; i++)
    {
        location.x = 0;
        location.y = 0;
        quantity = 0;

        resolve(regions[i], &location, &quantity, test_size);

        if (quantity > outputQuantity)
        {
            outputQuantity = quantity;
            output.x = location.x;
            output.y = location.y;
        }
        else if (location.x + location.y < output.x + output.y)
        {
            outputQuantity = quantity;
            output.x = location.x;
            output.y = location.y;
        }
        else if (location.x + location.y == output.x + output.y)
        {
            if (location.x < output.y)
            {
                outputQuantity = quantity;
                output.x = location.x;
                output.y = location.y;
            }
        }
    }

    printf("%d %d %d\n", output.x, output.y, outputQuantity);

    return 0;
}
