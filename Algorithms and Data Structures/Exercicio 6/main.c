#include <stdio.h>
#include <stdlib.h>

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

            break;
        }
        else if (list->degree > degree)
        {
            if (list->nextList != NULL)
            {
                list = list->nextList;
                if (degree < list->degree)
                    continue;
            }
            else
            {
                newList->previousList = list;
                list->nextList = newList;
                break;
            }
        }

        list = list->nextList;
    } while (list->nextList != NULL);

    return topList;
}

List *remove(List *topList, List *removeList)
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

int main()
{

    return 0;
}
