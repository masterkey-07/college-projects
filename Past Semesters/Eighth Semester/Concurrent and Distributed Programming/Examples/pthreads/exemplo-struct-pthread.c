#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_COUNT 10

#define MAX_THREADS 20

struct thread_data{
  int thread_id;
  double somaParcial;
};

struct thread_data thread_data_array[MAX_THREADS];

/* thread process prototype */
void *ThreadProcess(void *th);

int main(void) {
  pthread_t t[MAX_THREADS];
  int i;
  void *status;

  for(i=0; i<MAX_THREADS; i++) {
    thread_data_array[i].thread_id = i+1;
    pthread_create(&t[i], NULL, &ThreadProcess, (void *) &thread_data_array[i]);
  }

  for(i=0; i<MAX_THREADS; i++) {
    pthread_join(t[i], &status);
    printf("Main: from thread %d,sum=%g\n", 
	   i+1, thread_data_array[i].somaParcial);
  }

  
  
  pthread_exit(NULL);
  return 0;
}

void *ThreadProcess(void *threadarg) {
  int i, thid;
  double somaLocal;
  struct thread_data *my_data;

  my_data = (struct thread_data *) threadarg;
  thid = (int) my_data->thread_id;
  for (i=1; i<=MAX_COUNT; i++) {
    printf("Line from thread %d,value=%d\n", thid, i);
  }
  somaLocal = thid*2;
  my_data->somaParcial = somaLocal;

  pthread_exit(NULL);
}

