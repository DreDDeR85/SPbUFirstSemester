#include "twoLinkedList.h"

typedef struct Unit
{
    int value;
    struct Unit *prev;
    struct Unit *next;
} Unit;

struct TwoLinkedList
{
    Unit *left;
    Unit *right;
    int size;
};

TwoLinkedList *creatingTwoLinkedList()
{
    TwoLinkedList *twoLinkedList = calloc(1, sizeof(TwoLinkedList));
    if (twoLinkedList == NULL)
    {
        return NULL;
    }
    twoLinkedList->right = NULL;
    twoLinkedList->left = NULL;
    twoLinkedList->size = 0;
    return twoLinkedList;
}

int addingElement(TwoLinkedList *twoLinkedList, int value)
{
    if (twoLinkedList == NULL)
    {
        return -1;
    }
    Unit *rightHead = twoLinkedList->right;
    if (rightHead == NULL)
    {
        rightHead = calloc(1, sizeof(Unit));
        if (rightHead == NULL)
        {
            return -1;
        }
        rightHead->value = value;
        rightHead->prev = NULL;
        rightHead->next = NULL;
        twoLinkedList->right = rightHead;
        twoLinkedList->left = rightHead;
        twoLinkedList->size++;
    }
    else
    {
        Unit *newUnit = calloc(1, sizeof(Unit));
        if (newUnit == NULL)
        {
            return -1;
        }
        newUnit->prev = rightHead;
        newUnit->next = NULL;
        newUnit->value = value;
        twoLinkedList->right->next = newUnit;
        twoLinkedList->right = newUnit;
        twoLinkedList->size++;
    }
    return 0;
}

void clearTwoLinkedList(TwoLinkedList *twoLinkedList)
{
    if (twoLinkedList == NULL)
    {
        return;
    }
    Unit *unitToDelete = twoLinkedList->right;
    if (unitToDelete == twoLinkedList->left && unitToDelete == NULL)
    {
        free(twoLinkedList);
        return;
    }
    while (unitToDelete != NULL)
    {
        twoLinkedList->right = unitToDelete->prev;
        free(unitToDelete);
        unitToDelete = twoLinkedList->right;
    }
    free(twoLinkedList);
    return;
}

bool isTwoLinkedListSymmetric(TwoLinkedList *twoLinkedList)
{
    if (twoLinkedList == NULL)
    {
        return true;
    }
    if (twoLinkedList->right == NULL && twoLinkedList -> left == NULL)
    {
        return true;
    }
    Unit *rightPointer = twoLinkedList->right;
    Unit *leftPointer = twoLinkedList->left;
    for (int i = 0; i < twoLinkedList->size / 2; ++i)
    {
        if (leftPointer->value != rightPointer->value)
        {
            return false;
        }
        leftPointer = leftPointer->next;
        rightPointer = rightPointer->prev;
    }
    return true;
}

void printTwoLinkedList(TwoLinkedList *twoLinkedList)
{
    if (twoLinkedList == NULL)
    {
        return;
    }
    Unit *helpUnit = twoLinkedList->left;
    if (helpUnit == NULL)
    {
        return;
    }
    for (int i = 0; i < twoLinkedList->size; ++i)
    {
        printf("%d ", helpUnit->value);
        helpUnit = helpUnit->next;
    }
    printf("\n");
}
