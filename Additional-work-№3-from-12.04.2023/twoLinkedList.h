#pragma once

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TwoLinkedList TwoLinkedList;

TwoLinkedList *creatingTwoLinkedList();

int addingElement(TwoLinkedList *twoLinkedList, int value);

void clearTwoLinkedList(TwoLinkedList *twoLinkedList);

void printTwoLinkedList(TwoLinkedList *twoLinkedList);

bool isTwoLinkedListSymmetric(TwoLinkedList *twoLinkedList);