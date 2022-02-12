#include <stdio.h>
#include <math.h>

double squareRoot(double N, double A, double E)
{
    double result = (A * A) - N;

    if (result < 0.0)
        result = -result;

    if (result < E)
        return A;
    else
        return squareRoot(N, ((A * A) + N) / (2.0 * A), E);
}

int main()
{
    double n, a, e;

    scanf("%lf %lf %lf", &n, &a, &e);

    printf("%lf", squareRoot(n, a, e));

    return 0;
}
