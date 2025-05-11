# 2024 Exercício 1 - Compiladores

Instruções:

1. Compile o seu programa usando o compilador GCC em linha de comando;
2. Utilize o [Valgrind](https://www.ic.unicamp.br/~rafael/materiais/valgrind.html) para verificar vazamentos de memoria e se toda memória alocada foi desalocada
3. Apresente o resultado do seu programa na linha de comando;
4. Com exceção das funções para manipulação de arquivo, I/O e atoi, nenhuma
   outra função de bibliotecas padrão ao deve ser utilizada.

## Exercício 1.

Projete um programa que troque as vogais minusculas por maiúsculas e as maiúsculas por minusculas usando um buffer. Para isso, seu programa deve ser dividido em três
arquivos: main.c, funcs.h e funcs.c.
No arquivo main.c voce deve apenas:

1. verificar se o numero de parâmetros passado para o programa na linha de comando está correto, caso contrário encerre o programa. (Usar a função scanf para ler da linha de comando **não** é o mesmo que passar os parâmetros para o programa na linha de comando.) Os dois parâmetros são: 1) o nome do arquivo e 2) um inteiro que representa o tamanho do buffer.
2. abrir o arquivo e verificar se ele foi aberto corretamente, caso contrário encerre o programa;
3. alocar a estrutura de dados do buffer chamando a função allocate buffer do arquivo funcs.c;
4. chamar a função replace_print que realizará a substituição das vogais e mostrará o resultado na tela;
5. chamar a função deallocate_buffer que desaloca a memória do buffer;
6. fechar o arquivo.

No arquivo funcs.c, voce deve implementar as funções: allocate_buffer, deallocate_buffer e replace_print.

Na função replace_print, voce deve ler um caractere por vez do arquivo
e inserir no buffer até que este esteja completo. Então imprima o resultado do buffer.

Repita esse procedimento até que todo o arquivo seja lido.

No arquivo funcs.h voce deve declarar a estrutura de dados que conter a o buffer.

Essa estrutura deve conter um ponteiro para o buffer, e um inteiro para armazenar o tamanho do buffer.
