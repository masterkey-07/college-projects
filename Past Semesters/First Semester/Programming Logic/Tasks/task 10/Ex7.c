#include <stdio.h>
#include <math.h>

void getPolarsCoordenates(double x, double y, double *p, double *d)
{
    *p = sqrt((x * x) + (y * y));

    *d = 0.0;

    while (y / x > tan(*d))
        *d += 0.000001;
}

int main()
{

    double x, y, p, d;

    scanf("%lf %lf", &x, &y);

    getPolarsCoordenates(x, y, &p, &d);

    printf("%lf %lf", p, d);

    return 0;
}