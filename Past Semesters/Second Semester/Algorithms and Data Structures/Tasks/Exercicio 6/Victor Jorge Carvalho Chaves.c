

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Aluno: Victor Jorge Carvalho Chaves
R.A: 156.740
Turma: NB
*/

#define TRUE 1
#define FALSE 0

typedef struct DoubleList
{
    int coefficient;
    int degree;
    struct DoubleList *nextList;
    struct DoubleList *previousList;
} List;

List *allocateListMemory()
{
    return (List *)malloc(sizeof(List));
}

List *removeFromList(List *topList, List *removeList)
{
    List *list = topList;

    while (list != NULL)
    {
        if (list == removeList)
        {
            if (list->nextList == NULL && list->previousList == NULL)
                return NULL;
            else if (list->previousList == NULL)
            {
                list = list->nextList;
                list->previousList = NULL;
                topList = list;

                break;
            }
            else if (list->nextList == NULL)
            {
                list = list->previousList;
                list->nextList = NULL;

                break;
            }

            list = removeList->previousList;
            list->nextList = removeList->nextList;
            list = removeList->nextList;
            list->previousList = removeList->previousList;

            break;
        }
        list = list->nextList;
    }

    free(removeList);

    return topList;
}

List *insertByDegree(List *topList, int coefficient, int degree)
{
    List *newList = allocateListMemory();
    newList->coefficient = coefficient;
    newList->degree = degree;
    newList->previousList = NULL;
    newList->nextList = NULL;

    if (topList == NULL)
        return newList;

    List *list = topList;

    do
    {
        if (list->degree < degree)
        {
            if (list->previousList == NULL)
            {
                newList->nextList = list;
                topList = newList;
                break;
            }

            newList->previousList = list->previousList;
            newList->nextList = list;
            list->previousList = newList;
            list = newList->previousList;
            list->nextList = newList;

            break;
        }
        else if (list->degree == degree)
        {
            list->coefficient += coefficient;

            if (list->coefficient == 0)
                topList = removeFromList(topList, list);

            break;
        }
        else if (list->degree > degree)
        {
            if (list->nextList == NULL)
            {
                newList->previousList = list;
                list->nextList = newList;
                break;
            }
        }

        list = list->nextList;
    } while (list != NULL);

    return topList;
}

List *search(List *list, int degree)
{
    while (list != NULL)
    {
        if (list->degree == degree)
            return list;

        list = list->nextList;
    }

    return NULL;
}

List *negativeList(List *toplist)
{

    List *list = toplist;

    while (list != NULL)
    {
        list->coefficient = -list->coefficient;

        list = list->nextList;
    }

    return toplist;
}

void freeList(List *list)
{
    if (list != NULL)
    {
        freeList(list->nextList);
        free(list);
    }
}

int getNumber(char *string, int start, int end)
{
    int i;
    int result = 0;
    int x;
    for (i = start; i <= end; i++)
    {
        x = (((int)string[i]) - 48) * pow(10, end - i);

        result += (((int)string[i]) - 48) * pow(10, end - i);
    }

    if (result > 100)
        result++;

    return result;
}

int verifyNumber(char number)
{
    if (number >= 48 && number <= 57)
        return TRUE;
    else
        return FALSE;
}

List *readList()
{
    char stringPolynomial[100];
    int i = -1, j = 0;
    int isPower = FALSE;
    int isExponent = TRUE;
    int exponent;
    int power;
    int negative = 1;
    List *list = NULL;

    scanf("%[^\n]%*c", stringPolynomial);

    while (stringPolynomial[++i] != '\0')
    {
        if (verifyNumber(stringPolynomial[i]) == TRUE)
        {
            j = i + 1;
            while (verifyNumber(stringPolynomial[j]) == TRUE)
                j++;

            j--;

            if (isExponent == TRUE)
            {
                exponent = getNumber(stringPolynomial, i, j) * negative;

                negative = 1;
                isExponent = FALSE;
                isPower = TRUE;
            }
            else if (isPower == TRUE)
            {
                power = getNumber(stringPolynomial, i, j) * negative;
                list = insertByDegree(list, exponent, power);

                negative = 1;
                isExponent = TRUE;
                isPower = FALSE;
            }

            i = j;
        }
        else if (stringPolynomial[i] == '+' || stringPolynomial[i] == '-')
        {
            if (stringPolynomial[i] == '+')
                negative = 1;
            if (stringPolynomial[i] == '-')
                negative = -1;
        }
    }

    return list;
}

void printList(List *list)
{
    while (list != NULL)
    {
        if (list->coefficient > 0)
            printf("+");

        printf("%dx^%d ", list->coefficient, list->degree);
        list = list->nextList;
    }

    printf("\n");
}

List *sumLists(List *listA, List *listB)
{
    List *sumList = NULL;

    while (listA != NULL)
    {
        sumList = insertByDegree(sumList, listA->coefficient, listA->degree);
        listA = listA->nextList;
    }

    while (listB != NULL)
    {
        sumList = insertByDegree(sumList, listB->coefficient, listB->degree);
        listB = listB->nextList;
    }

    return sumList;
}

List *derivateList(List *list)
{
    List *derivatedList = NULL;

    while (list != NULL)
    {
        derivatedList = insertByDegree(derivatedList, list->coefficient * list->degree, list->degree - 1);
        list = list->nextList;
    }

    return derivatedList;
}

int showMenu()
{
    int result;

    printf("1- Inserir novso polinomios\n");
    printf("2- Somar polinomios\n");
    printf("3- Subtrair novso polinomios\n");
    printf("4- Derivar polinomio\n");
    printf("5- Sair\n");

    scanf("%d", &result);

    return result;
}

int main()
{
    int result = 0;
    List *polynomialA, *polynomialB;

    printf("Digite o primeiro polinomio:");
    polynomialA = readList();
    printf("Digite o segundo polinomio:");
    polynomialB = readList();

    while (result != 5)
    {
        result = showMenu();

        if (result == 1)
        {
            freeList(polynomialA);
            freeList(polynomialB);

            polynomialA = NULL;
            polynomialB = NULL;

            printf("Digite o primeiro polinomio:");
            polynomialA = readList();
            printf("Digite o segundo polinomio:");
            polynomialB = readList();
        }
        else if (result == 2)
        {

            List *sumList = sumLists(polynomialA, polynomialB);

            printList(sumList);

            freeList(sumList);
        }
        else if (result == 3)
        {
            polynomialB = negativeList(polynomialB);

            List *sumList = sumLists(polynomialA, polynomialB);

            polynomialB = negativeList(polynomialB);

            printList(sumList);

            freeList(sumList);
        }
        else if (result == 4)
        {
            List *derivatedList = NULL;
            printf("1-Primeiro Polinomio\n2-Segundo Polinomio\n");
            scanf("%d", &result);

            if (result == 1)
                derivatedList = derivateList(polynomialA);
            else
                derivatedList = derivateList(polynomialB);

            printList(derivatedList);
            freeList(derivatedList);
        }
    }

    freeList(polynomialA);
    freeList(polynomialB);
    return 0;
}
