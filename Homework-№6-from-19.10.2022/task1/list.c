#include <stdio.h>
#include "list.h"

typedef struct Unit
{
    int value;
    struct Unit *prev;
} Unit;

struct ListWithSort
{
    Unit *head;
};

void printListWithSort(ListWithSort *listWithSort)
{
    if (!isListWithSortEmpty(listWithSort))
    {
        Unit *helpUnit = listWithSort->head;
        while (helpUnit->prev != NULL)
        {
            printf("%d ", helpUnit->value);
            helpUnit = helpUnit->prev;
        }
        printf("%d\n", helpUnit->value);
    }
}

int putUnit(ListWithSort *listWithSort, int value)
{
    if (listWithSort == NULL)
    {
        return -5;
    }
    Unit *thisUnit = listWithSort->head;
    Unit *futureUnit = calloc(1, sizeof(Unit));
    if (futureUnit == NULL)
    {
        return -1;
    }
    futureUnit->value = value;
    if (isListWithSortEmpty(listWithSort))
    {
        futureUnit->prev = NULL;
        listWithSort->head = futureUnit;
        return 0;
    }
    if (thisUnit != NULL && value > thisUnit->value)
    {
        futureUnit->prev = thisUnit;
        listWithSort->head = futureUnit;
        return 0;
    }
    while (thisUnit->prev != NULL && value <= thisUnit->prev->value)
    {
        thisUnit = thisUnit->prev;
    }
    futureUnit->prev = thisUnit->prev;
    thisUnit->prev = futureUnit;
    return 0;
}

int deleteUnit(ListWithSort *listWithSort, int value)
{
    if (isListWithSortEmpty(listWithSort))
    {
        return -2;
    }
    Unit *thisUnit = listWithSort->head;
    if (thisUnit->value == value)
    {
        listWithSort->head = thisUnit->prev;
        free(thisUnit);
        return 0;
    }
    while (thisUnit->prev != NULL && thisUnit->prev->value != value)
    {
        thisUnit = thisUnit->prev;
    }
    if (thisUnit->prev == NULL)
    {
        return -3;
    }
    Unit *unitToDelete = thisUnit->prev;
    thisUnit->prev = unitToDelete->prev;
    free(unitToDelete);
    return 0;
}

bool isListWithSortEmpty(ListWithSort *listWithSort)
{
    return listWithSort == NULL || listWithSort->head == NULL;
}

int eraseListWithSort(ListWithSort *listWithSort)
{
    if (isListWithSortEmpty(listWithSort))
    {
        return -4;
    }
    Unit *headToDelete = NULL;
    Unit *newHead = NULL;
    while (isListWithSortEmpty(listWithSort))
    {
        headToDelete = listWithSort->head;
        newHead = headToDelete->prev;
        listWithSort->head = newHead;
        free(headToDelete);
    }
    free(listWithSort);
    return 0;
}

ListWithSort *generateListWithSort()
{
    ListWithSort *newListWithSort = calloc(1, sizeof(ListWithSort));
    newListWithSort->head = NULL;
    return newListWithSort;
}

