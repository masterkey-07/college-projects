# Exercício: Introdução à Avaliação de Desempenho

**Avaliação de Desempenho de um Algoritmo de Compressão de Dados**

Implemente o algoritmo de compressão Run-Length Encoding (RLE) em duas versões: uma utilizando a linguagem C e outra em qualquer outra linguagem de sua escolha. Desenvolva versões sequenciais e paralelas em ambas as linguagens, utilizando threads na versão paralela para dividir o processamento dos dados.

Realize medições de desempenho para diferentes tamanhos de entrada e diferentes números de threads. Ao final, produza um gráfico comparando o tempo de execução das versões em C com a outra linguagem escolhida, tanto na execução sequencial quanto na paralela, e identifique possíveis gargalos no processo de paralelização.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void compress_rle(const char* input, char* output) {
    int count, i = 0, j = 0;
    while (input[i] != '\0') {
        output[j++] = input[i];
        count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        j += sprintf(&output[j], "%d", count);
        i++;
    }
    output[j] = '\0';
}

int main() {
    char input[] = "aaabbccccddddeeeeeff";
    char output[100];

    clock_t start = clock();
    compress_rle(input, output);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("String comprimida: %s\n", output);
    printf("Tempo de execução (sequencial): %f segundos\n", time_spent);

    return 0;
}
```

```mermaid
xychart-beta
    title "Sales Revenue"
    x-axis [jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec]
    y-axis "Revenue (in $)" 4000 --> 11000
    bar [5000, 6000, 7500, 8200, 9500, 10500, 11000, 10200, 9200, 8500, 7000, 6000]
    line [5000, 6000, 7500, 8200, 9500, 10500, 11000, 10200, 9200, 8500, 7000, 6000]

```
