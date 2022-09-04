#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <dirent.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <math.h>

#define BSIZE 1024

sem_t mutex_mapper;
sem_t mutex_shuffler;
sem_t mutex_reducer;
sem_t mutex_remove;

sem_t full_mapper;
sem_t full_shuffler;
sem_t full_split;
sem_t sem_reducing_count;

int mapping_count = 0;
int shuffling_count = 0;
int reducing_count = 0;

int shuffling_count_mapping = 0;
int reducing_count_shuffling = 0;

int n_split = 0;

char matrix_buffer[30][BSIZE];
char matrix_words[BSIZE][50];

struct thread_t {
	pthread_t t;
	int id;
};
typedef struct thread_t thread_t;

struct store_split {
	char split_list[BSIZE][50];
};
typedef struct store_split store_split;
store_split mapping_contents[BSIZE];

void init(void) {
	sem_init(&mutex_mapper, 0, 1);
	sem_init(&mutex_shuffler, 0, 1);
	sem_init(&mutex_reducer, 0, 0);
	sem_init(&mutex_remove, 0, 0);
	
	sem_init(&full_mapper, 0, 0);
	sem_init(&full_shuffler, 0, 0);
	sem_init(&full_split, 0, n_split);

	sem_init(&sem_reducing_count, 0, 0);
}

void create_threads(thread_t *th, int n, void *(*func)(void*)) {
	int i;
	for (i = 0; i < n; i++) {
		th[i].id = i;
		pthread_create(&th[i].t, NULL, func, &th[i].id);
	}
}

void join_threads(thread_t *th, int n) {
	int i;
	for (i = 0; i < n; i++) {
		pthread_join(th[i].t, NULL);
	}
}

int thread_number(char **argv) {
	char dir_file[BSIZE];
	struct stat buff;
	
	stat(argv[1], &buff);
	return floor(buff.st_size/100); // a cada 100 letras cria uma thread
}

int splitter(char **argv) {
	char buffer[BSIZE];
	int count = 0;
	
	FILE *file;

	file = fopen(argv[1], "rb");
	fread(&buffer, sizeof(char), sizeof(buffer), file);

	char *tk = strtok(buffer, "."); // separa por pontos "."
	while (tk) {
		strcpy(matrix_buffer[count], tk);
		tk = strtok(NULL, ".");
		count++;
	}
	fclose(file);
	return count-1;
}

int find_word(char *word) {
	int i;
	for (i = 0; i < shuffling_count; i++) {
		if (!strcmp(word, matrix_words[i])) {
			return i;
		}
	}
	return -1;
}

void *mapper(void *args) {
	int id = *(int *)args;
	while (1) {
		sem_wait(&full_split);
		sem_wait(&mutex_mapper);

		char *content = matrix_buffer[mapping_count];
		char *delimiter = "!?:()-@#$%&, ";
		char *tk;

		tk = strtok(content, delimiter);
		int i = 0;
		while (tk) {
			tk[0] = tolower(tk[0]); // primeira letra minuscula
			strcpy(mapping_contents[mapping_count].split_list[i], tk);
			strcat(mapping_contents[mapping_count].split_list[i], ", 1");
			tk = strtok(NULL, delimiter);
			i++;
		}
		mapping_count++;
		sem_post(&full_mapper);
		sem_post(&mutex_mapper);
	}
}

void *shuffler(void *args) {	
	int id = *(int *)args;
	while (1) {
		sem_wait(&full_mapper);
		sem_wait(&mutex_shuffler);

		FILE *file;

		int i;
		int indice;
		for (i = 0; i < mapping_contents[shuffling_count_mapping].size; i++) {
		
			indice = find_word(mapping_contents[shuffling_count_mapping].split_list[i]);
			char shuffling_file[50];
			char mode[10];
			if (indice >= 0) {
				sprintf(shuffling_file, "shuffling_%d.txt", indice);
				strcpy(mode, "a");
			} else {
				sprintf(shuffling_file, "shuffling_%d.txt", shuffling_count);
				strcpy(mode, "wb");
				strcpy(matrix_words[shuffling_count], mapping_contents[shuffling_count_mapping].split_list[i]);
				shuffling_count++;
				sem_post(&full_shuffler);
			}
			file = fopen(shuffling_file, mode);
			fprintf(file, "%s\n", mapping_contents[shuffling_count_mapping].split_list[i]);
			fclose(file);
		}

		shuffling_count_mapping++;
		
		if (shuffling_count_mapping == n_split) {
			sem_post(&mutex_reducer);
		}

		sem_post(&mutex_shuffler);
	}
}

void *reducer(void *args) {
	int id = *(int *)args;
	while (1) {

		sem_wait(&mutex_reducer);
		sem_wait(&full_shuffler);

		FILE *file;
		if (reducing_count == 0) {
			file = fopen("output.txt", "wb");
		} else {
			file = fopen("output.txt", "a");
		}
		
		FILE *file_shuffler;
		char buffer[BSIZE];
		char shuffling_file[30];
		
		sprintf(shuffling_file, "shuffling_%d.txt", reducing_count);
		file_shuffler = fopen(shuffling_file, "rb");
		fread(&buffer, sizeof(char), sizeof(buffer), file_shuffler);

		int resultado = 0;
		char word[30];
		char *tk = strtok(buffer, "\n");
		strcpy(word, tk);

		while (tk) {
			tk = strtok(NULL, "\n");
			resultado++;
		}

		char *word_tk = strtok(word, " ");
		fprintf(file, "%s %d\n", word_tk, resultado);

		fclose(file_shuffler);
		fclose(file);	
		
		reducing_count++;		
		sem_post(&sem_reducing_count);
		
		if (reducing_count == shuffling_count) {
			sem_post(&mutex_remove);
		}
		
		sem_post(&mutex_reducer);
	}
}

void *remove_file(void *args) {
	int id = *(int *)args;
	while (1) {

		sem_wait(&mutex_remove);
		sem_wait(&sem_reducing_count);
	
		int value;
		sem_getvalue(&sem_reducing_count, &value);
		
		char shuffling_file[30];
		sprintf(shuffling_file, "shuffling_%d.txt", value);
		remove(shuffling_file);
		
		if (value == 0) {
			printf("output.txt gerado com sucesso!\n");
		}
		
		sem_post(&mutex_remove);
	} 
}

int main(int argc, char **argv) {
	int n_threads;
	
	if (argc < 2) {
		perror("argumentos insuficientes: <dir_file>");
	}
	
	n_threads = thread_number(argv);
	n_split = splitter(argv);
	init();

	thread_t t_mapper[n_threads], t_shuffler[n_threads], t_reducer[n_threads], t_remove[n_threads];

	create_threads(t_mapper, n_threads, mapper);
	create_threads(t_shuffler, n_threads, shuffler);
	create_threads(t_reducer, n_threads, reducer);
	create_threads(t_remove, n_threads, remove_file);

	join_threads(t_mapper, n_threads);
	join_threads(t_shuffler, n_threads);
	join_threads(t_reducer, n_threads);
	join_threads(t_remove, n_threads);
	
	return 0;
}
