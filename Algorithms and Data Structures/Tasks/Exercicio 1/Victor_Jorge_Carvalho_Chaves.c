/*
Aluno: Victor Jorge Carvalho Chaves
RA: 156.740
Turma: NB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAR_FORMAT "%s %s %d %s %d %d %c "
#define CAR_FILE "carros.txt"
#define WRITE "w"
#define READ "r"
#define ADD "a"
#define TRUE 0
#define FALSE 1

//Estrutura do Carro
struct Car
{
    char brand[15];
    char model[25];
    int yearOfFabrication;
    char licensePlate[6];
    int mileage;
    int numberOfDoors;
    char airConditioning;
};

// Aloca a memória do Struct Car no Ponteiro,e retorna esse valor
struct Car *allocateCarMemory()
{
    return (struct Car *)malloc(sizeof(struct Car));
}

//Lê os dados do carro que o usuário inseriu pelo terminal,e retornar
struct Car *insertCar()
{
    struct Car *car;

    car = allocateCarMemory();

    printf("\nMarca:");
    scanf("%s", &car->brand);
    printf("\nModelo:");
    scanf("%s", &car->model);
    printf("\nAno de Fabricacao:");
    scanf("%d", &car->yearOfFabrication);
    printf("\nPlaca do Carro:");
    scanf("%s", &car->licensePlate);
    printf("\nQuilometragem:");
    scanf("%d", &car->mileage);
    printf("\nNumeros de Portas:");
    scanf("%d", &car->numberOfDoors);
    printf("\nAr-Condicionado (s ou n):");
    scanf("%s", &car->airConditioning);

    return car;
}

//Printa os dados do carro
void printCar(struct Car *car)
{
    printf("\nMarca:");
    printf("%s", car->brand);
    printf("\nModelo:");
    printf("%s", car->model);
    printf("\nAno de Fabricacao:");
    printf("%d", car->yearOfFabrication);
    printf("\nPlaca do Carro:");
    printf("%s", car->licensePlate);
    printf("\nQuilometragem:");
    printf("%d", car->mileage);
    printf("\nNumeros de Portas:");
    printf("%d", car->numberOfDoors);
    printf("\nAr-Condicionado (s ou n):");
    printf("%c\n", car->airConditioning);
}

//Lê o arquivo texto passado por parametro e depois os dados lidos é inserido na variavel passada por parametro
int scanFile(FILE *f, struct Car *car)
{
    return fscanf(f, CAR_FORMAT, &car->brand, &car->model, &car->yearOfFabrication, &car->licensePlate, &car->mileage, &car->numberOfDoors, &car->airConditioning);
}

//Escreve no arquivo passado por parametro com os dados do carro
void writeFile(FILE *f, struct Car *car)
{
    fprintf(f, CAR_FORMAT, car->brand, car->model, car->yearOfFabrication, car->licensePlate, car->mileage, car->numberOfDoors, car->airConditioning);
}

//Printa na tela o menu e operações
int showMenu()
{
    int res;
    printf("\n\n1) Inserir novo cadastro de veiculo\n2) Alterar cadastro\n3) Mostrar os dados de um veiculo\n4) Apagar registro\n5) Sair\n");
    scanf("%d", &res);
    return res;
}

// Realizar todo o processo de inserção do carro no arquivo, lendo os dados passado pelo usuário e depois inserindo no arquivo.
void insertNewCar()
{
    struct Car *car = insertCar();

    FILE *f = fopen(CAR_FILE, ADD);

    writeFile(f, car);

    fclose(f);

    free(car);

    printf("Carro Inserido\n");
}

//Printa na tela a informação que ocorreu o erro de não ter encontrado o carro
void displayError()
{
    printf("Nao foi encontrado o carro.\n");
}

//Lê a placa que o usuário digitou pelo terminal
char *getLicensePlate()
{
    char *licensePlate = (char *)malloc(sizeof(char[6]));

    printf("Digite a placa do carro:");

    scanf("%s", licensePlate);

    return licensePlate;
}

//Procura o carro pela placa que está no arquivo texto, retornando um inteiro que significa TRUE ou FALSE, se achado,e o carro encontrado será armazenado na variavel passada por parametro
int findCar(char *licensePlate, struct Car *car)
{
    FILE *f = fopen(CAR_FILE, READ);

    while (scanFile(f, car) != EOF)
        if (strcmp(licensePlate, car->licensePlate) == TRUE)
        {
            fclose(f);
            return TRUE;
        }

    free(car);
    fclose(f);
    return FALSE;
}

//Faz todo o processo para printar o carro no terminal, primeiro pegando a placa digitada pelo usuario, procurando os dados desse carro e por fim printando os dados na tela
void displayCar()
{
    char *licensePlate = getLicensePlate();

    struct Car *car = allocateCarMemory();

    if (findCar(licensePlate, car) == TRUE)
        return printCar(car);

    free(car);
    displayError();
}

//Faz toda a operação de deletar um carro, primeiro lê a placa, pega todos os dados do arquivo texto e armazena em um vetor, limpa o arquivo texto e por fim insere todos os dados menos a do carro para ser deletado
void deleteCar()
{
    char *licensePlate = getLicensePlate();

    struct Car *cars[100];

    int i = 0, j = 0;

    int hasCar = FALSE;

    FILE *fr = fopen(CAR_FILE, READ);

    cars[i] = allocateCarMemory();

    while (scanFile(fr, cars[i++]) != EOF)
    {
        cars[i] = allocateCarMemory();
        if (strcmp(cars[i - 1]->licensePlate, licensePlate) == TRUE)
            hasCar = TRUE;
    }

    fclose(fr);

    if (hasCar == FALSE)
        displayError();
    else
    {
        FILE *fw = fopen(CAR_FILE, WRITE);

        for (j = 0; j < i - 1; j++)
            if (strcmp(cars[j]->licensePlate, licensePlate) != TRUE)
                writeFile(fw, cars[j]);

        fclose(fw);
    }

    for (j = 0; j < i; j++)
        free(cars[j]);

    printf("Carro Deletado");
}

//Informa para o usuario as opções de alteração de dados para o usuario, e depois lê a escolha do usuario
int getAlterationOption(struct Car *car)
{
    int res;

    printf("\nPlaca do Carro: %s", car->licensePlate);
    printf("\n1-Marca : %s", car->brand);
    printf("\n2-Modelo: %s", car->model);
    printf("\n3-Ano de Fabricacao: %d", car->yearOfFabrication);
    printf("\n4-Quilometragem: %d", car->mileage);
    printf("\n5-Numeros de Portas: %d", car->numberOfDoors);
    printf("\n6-Ar-Condicionado (s ou n): %c", car->airConditioning);
    printf("\n7-Sair\n");

    scanf("%d", &res);

    return res;
}

//Faz a operação de alterar os dados no arquivo, primeiro armazenando todos os dados dele em um vetor, limpa o arquivo e por fim insere novamente todos os dados, substituindo os dados do carro selecionado pelos dados novos digitados pelo usuario
void updateCars(struct Car *car)
{
    FILE *fr = fopen(CAR_FILE, READ);

    int i = 0, j = 0;

    struct Car *cars[100];

    cars[0] = allocateCarMemory();

    while (scanFile(fr, cars[i++]) != EOF)
        cars[i] = allocateCarMemory();

    fclose(fr);

    FILE *fw = fopen(CAR_FILE, WRITE);

    for (j = 0; j < i - 1; j++)
    {
        if (strcmp(car->licensePlate, cars[j]->licensePlate) != TRUE)
            writeFile(fw, cars[j]);
        else
            writeFile(fw, car);
    }

    free(car);
    for (j = 0; j < i; j++)
        free(cars[j]);

    fclose(fw);
}

//Faz toda a operação de alteração de dados de um carro, primeiro lê a placa, encontra o carro, permite a troca de dados desse carro, e por fim atualiza os dados no arquivo texto
void alterCar()
{
    char *licensePlate = getLicensePlate();

    struct Car *car = allocateCarMemory();

    if (findCar(licensePlate, car) == FALSE)
        return displayError();

    int res;
    while (TRUE == TRUE)
    {
        res = getAlterationOption(car);

        printf("Digite o valor:");

        if (res == 1)
            scanf("%s", &car->brand);
        else if (res == 2)
            scanf("%s", &car->model);
        else if (res == 3)
            scanf("%d", &car->yearOfFabrication);
        else if (res == 4)
            scanf("%d", &car->mileage);
        else if (res == 5)
            scanf("%d", &car->numberOfDoors);
        else if (res == 6)
            scanf("%s", &car->airConditioning);
        else if (res == 7)
        {
            updateCars(car);
            printf("Carro Atualizado\n");
            return;
        }
    }
}

//Função principal do projeto, irá executar todas as funcionalidades do programa.
int main(int argc, char const *argv[])
{
    while (TRUE == TRUE)
    {
        int res = showMenu();

        if (res == 1)
            insertNewCar();
        else if (res == 2)
            alterCar();
        else if (res == 3)
            displayCar();
        else if (res == 4)
            deleteCar();
        else if (res == 5)
            break;
    }

    return TRUE;
}
