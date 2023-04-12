#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ListWithSort ListWithSort;

/* All error codes for functions:
 * ==============================
 * -1 - Error while allocating memory for the new element!
 * -2 - Error while deleting the unit. There are deleting from nowhere!
 * -3 - There are no unit in this list with sort with that value!
 * -4 - We cannot erase the empty list with sort!
 * -5 - We cannot put value to the NULL list with sort!
 *
 * Error code for programs, which are based on list with sort:
 * ==================================================
 * */


//creating list with sort
ListWithSort *generateListWithSort();

//putting value to the list
int putUnit(ListWithSort *listWithSort, int value);

//printing the list
void printListWithSort(ListWithSort *listWithSort);

//deleting unit by value
int deleteUnit(ListWithSort *listWithSort, int value);

//erasing list with sort
int eraseListWithSort(ListWithSort *listWithSort);

//verifying is this list empty
bool isListWithSortEmpty(ListWithSort *listWithSort);