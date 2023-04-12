#include <stdio.h>
#include "twoLinkedList.h"

int main()
{
    printf("Hello! Please, give me on enter the natural number N - the amount of elements\n");
    printf("And then the N elements of two-linked list. I will check, if this list is a symmetric or not\n");
    int amount = 0, scanElem = 0;
    scanf("%d", &amount);
    TwoLinkedList *twoLinkedList = creatingTwoLinkedList();
    printf("Now, please, enter the N numbers, each one on the new line\n");
    for (int i = 0; i < amount; ++i)
    {
        scanf("%d", &scanElem);
        addingElement(twoLinkedList, scanElem);
    }
    printf("You have enter the next two-linked list:\n");
    printTwoLinkedList(twoLinkedList);
    bool answer = isTwoLinkedListSymmetric(twoLinkedList);
    if (answer)
    {
        printf("And this two-linked list is symmetric!\n");
    }
    else
    {
        printf("Unfortunately, bot this two-linked list is not symmetric.\n");
    }
    clearTwoLinkedList(twoLinkedList);
    return 0;
}
