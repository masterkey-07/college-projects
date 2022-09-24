#include <stdio.h>
#include <stdlib.h>

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
    Location location;
    int quantity;
};

typedef struct Region Region;

Region *readRegion()
{
    Region *region = (Region *)malloc(sizeof(Region));

    scanf("%d", &region->location.x);
    scanf("%d", &region->location.y);
    scanf("%d", &region->quantity);

    return region;
}

int main(int argc, char const *argv[])
{
    int test_size, number_points, i;

    scanf("%d", &test_size);
    scanf("%d", &number_points);

    Region **regions = (Region **)malloc(sizeof(Region *) * number_points);

    for (i = 0; i < number_points; i++)
        regions[i] = readRegion();

    return 0;
}
