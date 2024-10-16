#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define N 1000000000
#define MAX_THREADS 2

void *calcula(void *res){
  int k;
  double p = 1 , x , y;
  x = 1 + 1.0/N;  
  for(k=0; k<(N/MAX_THREADS); k++)
    p = p*x;
  //copia valor p/variável de retorno
  *( (double*)res ) = p;  
} 

int main(void){
  pthread_t t[MAX_THREADS];
  double v[MAX_THREADS];
  double final;
  int i;

  clock_t start, end;

  struct timeval inicio, final2;
  int tmili;

  start = clock();

  gettimeofday(&inicio, NULL);
  
  for(i=0; i<MAX_THREADS; i++) {
    pthread_create(&t[i], NULL, &calcula, (void *) &v[i]);
  }

  final = 1.;
  for(i=0; i<MAX_THREADS; i++) {
    pthread_join(t[i],NULL);
    final = final*v[i];
  }

  gettimeofday(&final2, NULL);
  tmili = (int) (1000 * (final2.tv_sec - inicio.tv_sec) + (final2.tv_usec - inicio.tv_usec) / 1000);
  
  printf("tempo decorrido: %d milisegundos\n", tmili);

  printf("tempo decorrido tv_sec: %d\n", (int) (final2.tv_sec - inicio.tv_sec));

  printf("tempo decorrido tv_usec: %d\n", (int) (final2.tv_usec - inicio.tv_usec));

  printf("Time elapsed: %f\n", ((double)clock() - start)/ CLOCKS_PER_SEC);  

  printf("Resultado=%lf\n",final);
  return 0;
}  
