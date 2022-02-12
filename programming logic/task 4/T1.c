#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// CelsiusToFahrenheit
int main()
{
    //variavel
    float celsius, fahrenheit;

    //logica
    scanf("%f", &celsius);

    fahrenheit = (((celsius)*9.0) / 5.0) + 32.0;

    printf("%f", fahrenheit);

    return 0;
}