#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour, minutes;

    scanf("%d %d", &hour, &minutes);

    printf("%d", (hour * 60) + minutes);

    return 0;
}