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
    int quantity;
    Location location;
    struct List *relations;
};

typedef struct Region Region;

Region *readRegion(int index, int length)
{
    Region *region = (Region *)malloc(sizeof(Region));

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

int relatable(Location locationA, Location locationB, int size)
{
    int x = abs(locationA.x - locationB.x);
    int y = abs(locationA.y - locationB.y);

    int value = max(x, y);

    return value <= size ? TRUE : FALSE;
}

void relate(Region *regionA, Region *regionB, int size)
{
    if (relatable(regionA->location, regionB->location, size * 2) == TRUE)
    {
        regionA->relations = push(regionA->relations, regionB);
        regionB->relations = push(regionB->relations, regionA);
    }
}

int discover(int value, int d)
{
    return value - d > 0 ? value - d : 0;
}

void resolve(Region *region, Location *location, int *quantity, int d)
{
    location->x = discover(region->location.x, d);
    location->y = discover(region->location.y, d);
    *quantity = region->quantity;

    List *selected = region->relations;

    int counter;
    Location area;

    while (selected != NULL)
    {
        counter = region->quantity + selected->item->quantity;

        area.x = discover(max(region->location.x, selected->item->location.x), d);
        area.y = discover(max(region->location.y, selected->item->location.y), d);

        List *relations = region->relations;

        while (relations != NULL)
        {
            if (relations->item != region && relations->item != selected->item)
                if (relatable(area, relations->item->location, d) == TRUE)
                    counter += relations->item->quantity;

            relations = relations->next;
        }

        if (*quantity < counter)
        {
            location->x = area.x;
            location->y = area.y;
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
        else if (quantity == outputQuantity)
        {
            if (location.x + location.y < output.x + output.y)
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
    }

    printf("%d %d %d\n", output.x, output.y, outputQuantity);

    return 0;
}
