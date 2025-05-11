#include <omp.h>
#include "integral.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double seq_start, seq_end, par_start, par_end, seq_time_spent, par_time_spent;

    int threads, steps;

    FILE *file = fopen("output.csv", "w");

    fprintf(file, "threads,steps,seq,par\n");

    for (threads = 1; threads <= 12; threads++)
        for (steps = 1; steps <= 1000000000; steps = steps * 10)
        {
            printf("%d %d\n", threads, steps);

            seq_start = omp_get_wtime();
            sequencial_pi_calculator(steps);
            seq_end = omp_get_wtime();

            par_start = omp_get_wtime();
            parallel_pi_calculator(steps, threads);
            par_end = omp_get_wtime();

            seq_time_spent = (double)(seq_end - seq_start);
            par_time_spent = (double)(par_end - par_start);

            fprintf(file, "%d,%d,%lf,%lf\n", threads, steps, seq_time_spent, par_time_spent);
        }

    fclose(file);
}