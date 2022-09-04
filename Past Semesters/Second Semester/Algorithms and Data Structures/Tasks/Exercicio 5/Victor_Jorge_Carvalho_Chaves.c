/*
Aluno : Victor Jorge Carvalho Chaves
R.A : 156.740
Turma : NB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

typedef struct circleList
{
    char character;
    struct circleList *nextList;
} CircleList;

CircleList *createCircleList()
{
    return (CircleList *)malloc(sizeof(CircleList));
}

CircleList *push(CircleList *list, char character)
{
    CircleList *newList = createCircleList();
    newList->character = character;

    if (list == NULL)
    {
        list = newList;
        newList->nextList = newList;
    }
    else
    {
        newList->nextList = list->nextList;
        list->nextList = newList;
    }

    return list;
}

CircleList *pop(CircleList *list, char *character)
{
    CircleList *nextList;

    if (list == NULL)
        return NULL;

    nextList = list->nextList;
    character = nextList->character;
    list->nextList = nextList->nextList;

    if (nextList == list)
        return NULL;

    free(nextList);

    return list;
}

CircleList *readStringList()
{
    CircleList *list = NULL;
    char output[50];
    int i = -1;

    scanf("%s", output);

    while (output[++i] != '\0')
        list = push(list, output[i]);

    return list;
}

void freeCircleList(CircleList *list)
{
    freeList(list->nextList, list);
}

void freeList(CircleList *list, CircleList *endList)
{
    if (list != endList)
        freeList(list->nextList, endList);

    free(list);
}

void printList(CircleList *list, CircleList *endList)
{
    if (list != NULL)
    {
        printf("%c", list->character);

        if (list != endList)
            printList(list->nextList, endList);
    }
}

int calculatePoints(CircleList *substring, CircleList *string)
{
    int result;
    CircleList *endString = createCircleList();
    CircleList *startSubstring = createCircleList();
    endString = string;
    startSubstring = substring->nextList;
    string = string->nextList;

    while (string != endString)
    {
        if (string->character == startSubstring->character)
        {
            result = verifySubstring(startSubstring, string);
            if (result == TRUE)
                return countSubstring(substring);
        }

        string = string->nextList;
    }

    return 0;
}

int verifySubstring(CircleList *substring, CircleList *string)
{

    CircleList *endSubstring = createCircleList();
    endSubstring = substring;
    substring = substring->nextList;
    string = string->nextList;

    while (endSubstring != substring)
    {
        if (substring->character != string->character)
            return FALSE;

        substring = substring->nextList;
        string = string->nextList;
    }

    return TRUE;
}

int countSubstring(CircleList *substring)
{
    CircleList *endSubstring = createCircleList();
    endSubstring = substring;
    substring = substring->nextList;
    int total = 1;

    while (endSubstring != substring)
    {
        total++;
        substring = substring->nextList;
    }

    return total;
}

int main(int argc, char const *argv[])
{
    int numberSubstrings, i, minorPoint = 0, result, totalSubstrings = 0;

    printf("Digite o tamanho do conjunto de substrings: ");

    scanf("%d", &numberSubstrings);

    printf("Digite a string inicial (somente letras minusculas): ");

    CircleList *list = readStringList(), *secondList;

    printf("Digite, a seguir, as %d substring (uma por linha e todas com letras minusculas):\n", numberSubstrings);

    for (i = 0; i < numberSubstrings; i++)
    {
        secondList = readStringList();
        result = calculatePoints(secondList, list);
        if (result > 0)
        {
            if (minorPoint == 0)
                minorPoint = result;
            else if (minorPoint > result)
                minorPoint = result;

            totalSubstrings++;
        }

        freeCircleList(secondList);
    }

    printf("Numero de strings ciclicas: %d\n", totalSubstrings);
    printf("Menor pontuacao: %d", minorPoint);

    freeCircleList(list);

    return 0;
}
