#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    int th_id, nthreads;

    omp_set_num_threads(4);

#pragma omp parallel private(th_id)
    {
        th_id = omp_get_thread_num();
        printf("Hello World from thread %d\n", th_id);
        if (th_id == 0)
        {
            nthreads = omp_get_num_threads();
            printf("There are %d threads\n", nthreads);
        }
    }
    return 0;
}
