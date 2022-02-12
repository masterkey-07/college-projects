/*
Aluno : Victor Jorge Carvalho Chaves
R.A : 156.740
Turma : NB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    char value;
    struct Queue *queue;
};

struct Queue *createQueue()
{
    return (struct Queue *)malloc(sizeof(struct Queue));
}

// Add a Queue in a Start of a Queue
struct Queue *addQueue(struct Queue *queue, char value)
{
    struct Queue *newQueue = createQueue();

    newQueue->value = value;

    newQueue->queue = queue;

    return newQueue;
}

// Convert a Char to a Int
int convertChar(char value)
{
    return value - '0';
}

// Convert a Int to a Char
char convertInt(int value)
{
    return value + '0';
}

// Recursive Function to convert a Char to a Queue
struct Queue *convertToQueue(struct Queue *queue, char *number, int index)
{
    if (number[index] != '\0')
    {
        queue = convertToQueue(queue, number, index + 1);
        queue = addQueue(queue, number[index]);
    }
}

// Recursive Function to Print a Queue
void printQueue(struct Queue *queue)
{
    if (queue != NULL)
    {
        printf("%c", queue->value);
        printQueue(queue->queue);
    }
}

// Recursive Function to Calculate a Sum Between two Queue's
struct Queue *calculateSum(struct Queue *numberA, struct Queue *numberB, struct Queue *numberResult, int lengthA, int lengthB)
{
    int sum;

    if (lengthA == 0 && lengthB == 0)
        return NULL;

    if (lengthA == lengthB)
    {
        sum = convertChar(numberA->value) + convertChar(numberB->value);
        numberResult = calculateSum(numberA->queue, numberB->queue, numberResult, lengthA - 1, lengthB - 1);
    }
    else
    {
        if (lengthA > lengthB)
        {
            sum = convertChar(numberA->value);
            numberResult = calculateSum(numberA->queue, numberB, numberResult, lengthA - 1, lengthB);
        }
        else
        {
            sum = convertChar(numberB->value);
            numberResult = calculateSum(numberA, numberB->queue, numberResult, lengthA, lengthB - 1);
        }
    }

    if (numberResult != NULL)
        if (convertChar(numberResult->value) > 9)
        {
            numberResult->value = convertInt(convertChar(numberResult->value) % 10);
            return addQueue(numberResult, convertInt(sum + 1));
        }

    return addQueue(numberResult, convertInt(sum));
}

// Recursive Function to Free a Queue
void freeQueue(struct Queue *queue)
{
    if (queue != NULL)
    {
        freeQueue(queue->queue);
        free(queue);
    }
}

int main()
{
    char numberA[100], numberB[100];

    int lengthA, lengthB, result;

    struct Queue *queueA = NULL;
    struct Queue *queueB = NULL;
    struct Queue *queueResult = NULL;

    printf("Digite o primeiro numero: ");
    scanf("%s", numberA);

    printf("\nDigite o segundo numero: ");
    scanf("%s", numberB);

    lengthA = strlen(numberA);
    lengthB = strlen(numberB);

    queueA = convertToQueue(queueA, numberA, 0);
    queueB = convertToQueue(queueB, numberB, 0);

    queueResult = calculateSum(queueA, queueB, queueResult, lengthA, lengthB);

    if (convertChar(queueResult->value) > 9)
    {
        queueResult->value = convertInt(convertChar(queueResult->value) % 10);
        queueResult = addQueue(queueResult, convertInt(1));
    }

    printf("\nResultado da soma : ");
    printQueue(queueResult);

    freeQueue(queueA);
    freeQueue(queueB);
    freeQueue(queueResult);

    return 0;
}
