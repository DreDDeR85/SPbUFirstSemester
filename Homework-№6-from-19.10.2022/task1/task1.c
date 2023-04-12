#include "list.h"

void errorDispenser(int error)
{
    switch (error)
    {
        case -1:
            printf("Error while allocating memory for the new element!\n");
            break;
        case -2:
            printf("Error while deleting the unit. There are deleting from nowhere!\n");
            break;
        case -3:
            printf("There are no unit in this list with sort with that value!\n");
            break;
        case -4:
            printf("We cannot erase the empty list with sort!\n");
            break;
        case -5:
            printf("-5 - We cannot put value to the NULL list with sort!");
            break;
        default:
            break;
    }
}

bool tests()
{
    int keyFirstTest = 0, keySecondTest = 0, keyThirdTest = -3, keyFourthTest = 0, keyFifthTest = -3, keySixthTest = 0;
    ListWithSort *test = generateListWithSort();
    if (putUnit(test, 9) != keyFirstTest)
    {
        return false;
    }
    if (putUnit(test, 5) != keySecondTest)
    {
        return false;
    }
    if (deleteUnit(test, 0) != keyThirdTest)
    {
        return false;
    }
    if (deleteUnit(test, 9) != keyFourthTest)
    {
        return false;
    }
    if (deleteUnit(test, 9) != keyFifthTest)
    {
        return false;
    }
    if (eraseListWithSort(test) != keySixthTest)
    {
        return false;
    }
    return true;
}

void readInt(int *whatWeWannaToRead)
{
    int successRead = scanf("%d", whatWeWannaToRead);
    while (!successRead)
    {
        scanf("%*[^\n]");
        printf("Incorrect enter! Please, try again\n");
        successRead = scanf("%d", whatWeWannaToRead);
    }
}

int main()
{
    if (!tests())
    {
        printf("Tests didn't passed successfully!\n");
        return -7;
    }
    else
    {
        printf("Tests passed successfully!\n");
    }
    printf("Hello! I am a program, which can help you with work with a sorted list!\n");
    printf("I can do these commands:\n");
    printf("0 - exit\n"
                 "1 - add a value to the sorted list\n"
                 "2 - remove a value from the list\n"
                 "3 - print the list\n");
    printf("So, what you wanna do with me? Enter the integer number!\n");
    int action = -1, potentialValue = 0, leaver = 0;
    ListWithSort *myList = generateListWithSort();
    while (action != 0)
    {
        printf("Enter the number of action:");
        readInt(&action);
        switch (action)
        {
            case 1:
                printf("Enter the value which you wanna to put:");
                readInt(&potentialValue);
                errorDispenser(putUnit(myList, potentialValue));
                break;
            case 2:
                printf("Enter the value which you wanna to delete:");
                readInt(&potentialValue);
                errorDispenser(deleteUnit(myList, potentialValue));
                break;
            case 3:
                printListWithSort(myList);
                break;
            case 0:
                leaver = 1;
                break;
            default:
                printf("Incorrect enter! Please, try again\n");
        }
        if (leaver)
        {
            break;
        }

    }
    if (isListWithSortEmpty(myList))
    {
        eraseListWithSort(myList);
    }
    return 0;
}