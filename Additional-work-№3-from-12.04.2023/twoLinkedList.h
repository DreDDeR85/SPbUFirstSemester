#pragma once

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TwoLinkedList TwoLinkedList;

//this function creates two-linked list
TwoLinkedList *creatingTwoLinkedList();

//this function lets you add value
//to the right side of two-linked list
int addingElement(TwoLinkedList *twoLinkedList, int value);

//this function erases all units of
//two-linked list and him itself
void clearTwoLinkedList(TwoLinkedList *twoLinkedList);

//this function prints on your screen
//two-linked list
void printTwoLinkedList(TwoLinkedList *twoLinkedList);

//this function checks if your two-linked list
//is symmetrical with respect to the center
bool isTwoLinkedListSymmetric(TwoLinkedList *twoLinkedList);
