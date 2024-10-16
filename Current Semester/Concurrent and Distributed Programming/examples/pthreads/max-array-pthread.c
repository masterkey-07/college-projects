#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N 100000000
#define MAX_THREADS 4

float *array;

float *retorno;

void *max(void *tid) {
  long thid;
  long i;
  float maxloc;

  thid = (long) tid;

  maxloc = array[thid];

  for(i=thid; i<N; i+=MAX_THREADS)
     if (array[i]>maxloc) maxloc = array[i];

  printf("thread=%ld, maximo local=%f\n", thid, maxloc);

  retorno[thid] = maxloc;

  pthread_exit(0);
} 

int main(void){
  pthread_t t[MAX_THREADS];
  float maxglobal;
  long i;
  long th;

  struct timeval inicio, final2;
  int tmili;

  array = (float*) malloc(N*sizeof(float));
  retorno = (float*) malloc(MAX_THREADS*sizeof(float));

  for(i=0; i<N; i++) 
     array[i] = i/1000.;

  gettimeofday(&inicio, NULL);
  
  for(th=0; th<MAX_THREADS; th++) {
    pthread_create(&t[th], NULL, max, (void *) th);
  }

  maxglobal = array[0];
  for(th=0; th<MAX_THREADS; th++) {
    pthread_join(t[th],NULL);
    if (retorno[th]>maxglobal) maxglobal = retorno[th];
  }

  gettimeofday(&final2, NULL);
  tmili = (int) (1000 * (final2.tv_sec - inicio.tv_sec) + (final2.tv_usec - inicio.tv_usec) / 1000);
  
  printf("tempo decorrido: %d milisegundos\n", tmili);

  printf("maior valor=%f\n",maxglobal);

  return 0;
}  
