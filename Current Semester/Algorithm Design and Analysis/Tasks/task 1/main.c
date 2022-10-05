#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define CITY_SIZE 1025

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

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main(int argc, char const *argv[])
{
    int d, number_points, i, j;

    scanf("%d", &d);
    scanf("%d", &number_points);

    Region **regions = (Region **)malloc(sizeof(Region *) * number_points);

    for (i = 0; i < number_points; i++)
        regions[i] = readRegion(i, number_points);

    int x, y, rX, rY, rQ = 0, count = 0;

    Region *region;

    for (x = 0; x < CITY_SIZE; x++)
    {
        for (y = 0; y < CITY_SIZE; y++)
        {
            count = 0;

            for (i = 0; i < number_points; i++)
            {
                Location location = regions[i]->location;

                if (max(abs(location.x - x), abs(location.y - y)) <= d)
                    count += regions[i]->quantity;
            }

            if (count > rQ)
            {
                rQ = count;
                rX = x;
                rY = y;
            }
        }
    }

    printf("%d %d %d\n", rX, rY, rQ);

    return 0;
}
