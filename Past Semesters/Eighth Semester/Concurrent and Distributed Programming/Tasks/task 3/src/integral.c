#include <omp.h>
#include <stddef.h>
#include "integral.h"

typedef unsigned long long toolong;

long double sequencial_pi_calculator(toolong num_steps)
{
    toolong i;
    long double step;
    long double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }

    pi = step * sum;

    return pi;
}

long double parallel_pi_calculator(toolong num_steps, int threads)
{
    toolong i;
    long double step;
    long double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

    omp_set_num_threads(threads);

#pragma omp parallel private(x)
    {
#pragma omp for reduction(+ : sum)
        for (i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }
    }
    pi = step * sum;

    return pi;
}
