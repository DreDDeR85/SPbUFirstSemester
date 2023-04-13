#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *readFromFile(char *nameOfTheFile, int *length)
{
    FILE *file = fopen(nameOfTheFile, "r");
    int amount = 0;
    fscanf(file, "%d", &amount);
    int *array = calloc(amount, sizeof(int));
    for (int i = 0; i < amount; ++i)
    {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);
    *length = amount;
    return array;
}

/*
 * for debug
void printArray(int *array, int arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
*/

void swap(int *firstElement, int *secondElement)
{
    int temp = *secondElement;
    *secondElement = *firstElement;
    *firstElement = temp;
}

int divide(int *array, int left, int right)
{
    int changingElem = left;
    for (int i = left; i < right; ++i)
    {
        if (array[i] < array[right])
        {
            swap(&array[changingElem], &array[i]);
            changingElem += 1;
        }
    }
    swap(&array[right], &array[changingElem]);
    return changingElem;
}

void quickSortRec(int *array, int left, int right)
{
    if (left < right)
    {
        int centerElem = divide(array, left, right);
        quickSortRec(array, left, centerElem - 1);
        quickSortRec(array, centerElem + 1, right);
    }
}

void quickSort(int *array, int lenOfArray)
{
    quickSortRec(array, 0, lenOfArray - 1);
}

int *intersection(int *firstArray, int lenOfTheFirstArray, int *secondArray, int lenOfTheSecondArray, int *lenOfIntersectionArray)
{
    int firstPointer = 0, secondPointer = 0, interArrayPointer = 0, maxLen = 0;
    if (lenOfTheFirstArray >= lenOfTheSecondArray)
    {
        maxLen = lenOfTheFirstArray;
    }
    else
    {
        maxLen = lenOfTheSecondArray;
    }
    int *intersectionArray = calloc(maxLen, sizeof(int));
    if (intersectionArray == NULL)
    {
        return NULL;
    }
    while (firstPointer != lenOfTheFirstArray && secondPointer != lenOfTheSecondArray)
    {
        if (firstArray[firstPointer] == secondArray[secondPointer])
        {
            intersectionArray[interArrayPointer] = firstArray[firstPointer];
            firstPointer++;
            interArrayPointer++;
        }
        else if (firstArray[firstPointer] < secondArray[secondPointer])
        {
            firstPointer++;
        }
        else
        {
            secondPointer++;
        }
    }
    *lenOfIntersectionArray = interArrayPointer;
    return intersectionArray;
}

int *unionArrayFunc(int *firstArray, int lenOfTheFirstArray, int *secondArray, int lenOfTheSecondArray, int *lenOfunionArray)
{
    int firstPointer = 0, secondPointer = 0, unionArrayPointer = 0;
    int sumLen = lenOfTheFirstArray + lenOfTheSecondArray;
    int *unionArray = calloc(sumLen, sizeof(int));
    if (unionArray == NULL)
    {
        return NULL;
    }
    while (firstPointer != lenOfTheFirstArray && secondPointer != lenOfTheSecondArray)
    {
        if (firstArray[firstPointer] == secondArray[secondPointer])
        {
            unionArray[unionArrayPointer] = firstArray[firstPointer];
            unionArrayPointer++;
            firstPointer++;
            secondPointer++;
        }
        else if (firstArray[firstPointer] < secondArray[secondPointer])
        {
            unionArray[unionArrayPointer] = firstArray[firstPointer];
            unionArrayPointer++;
            firstPointer++;
        }
        else
        {
            unionArray[unionArrayPointer] = secondArray[secondPointer];
            unionArrayPointer++;
            secondPointer++;
        }
    }
    if (firstPointer == lenOfTheFirstArray)
    {
        for (int i = secondPointer; i < lenOfTheSecondArray; ++i)
        {
            unionArray[unionArrayPointer] = secondArray[i];
            unionArrayPointer++;
        }
    }
    else if (secondPointer == lenOfTheSecondArray)
    {
        for (int i = firstPointer; i < lenOfTheFirstArray; ++i)
        {
            unionArray[unionArrayPointer] = firstArray[i];
            unionArrayPointer++;
        }
    }
    *lenOfunionArray = unionArrayPointer;
    return unionArray;
}

int *difference(int *firstArray, int lenOfTheFirstArray, int *secondArray, int lenOfTheSecondArray, int *lenOfTheDifference)
{
    int firstPointer = 0, secondPointer = 0, differencePointer = 0;
    int maxLen = lenOfTheFirstArray + lenOfTheSecondArray;
    int *differenceArray = calloc(maxLen, sizeof(int));
    if (differenceArray == NULL)
    {
        return NULL;
    }
    while (firstPointer != lenOfTheFirstArray && secondPointer != lenOfTheSecondArray)
    {
        if (firstArray[firstPointer] < secondArray[secondPointer])
        {
            differenceArray[differencePointer] = firstArray[firstPointer];
            firstPointer++;
            differencePointer++;
        }
        else if (firstArray[firstPointer] == secondArray[secondPointer])
        {
            firstPointer++;
        }
        else
        {
            secondPointer++;
        }
    }
    if (firstPointer != lenOfTheFirstArray)
    {
        for (int j = firstPointer; j < lenOfTheFirstArray; ++j)
        {
            differenceArray[differencePointer] = firstArray[firstPointer];
            differencePointer++;
            firstPointer++;
        }
    }
    *lenOfTheDifference = differencePointer;
    return differenceArray;
}

void arrayToFile(int *array, int lenOfArray, char* fileName)
{
    FILE *file = fopen(fileName, "w");
    for (int i = 0; i < lenOfArray; ++i)
    {
        fprintf(file, "%d ", array[i]);
    }
    fclose(file);
}

int main()
{
    printf("Hello! Please, be ready to use this program!\n");
    printf("You must prepare your files with names \"firstFile.txt\" and \"secondFile.txt\",\n");
    printf("where some integer numbers are presented\n");
    printf("Then check your folder with this program, because I will create\n");
    printf("four more files with different properties of numbers from your files!\n");
    printf("Do you ready to start? Yes - \"y\", no - any other symbol\n");
    char answer = ' ';
    scanf("%c", &answer);
    if (answer != 'y')
    {
        printf("Ok, when you prepared, launch me again!\n");
        return 0;
    }
    char firstFileName[] = "firstFile.txt", secondFileName[] = "secondFile.txt",
        intersectionFileName[] = "intersection.txt", unionFileName[] = "union.txt",
        symmDiffFileName[] = "symmetricDifference.txt", onlyInTheFirstFile[] = "onlyInTheFirstFile.txt";

    int lengthOfFirstFile = 0, lengthOfSecondFile = 0,
        lengthOfunionArray = 0,lengthOfIntersectionArray = 0,
        lengthOfSymmetricDifferenceArray = 0, lenOfOnlyInFirstArray = 0;

    int *arrayOfFirstFileNumbers = readFromFile(firstFileName, &lengthOfFirstFile);
    int *arrayOfSecondFileNumbers = readFromFile(secondFileName, &lengthOfSecondFile);

    quickSort(arrayOfFirstFileNumbers, lengthOfFirstFile);
    quickSort(arrayOfSecondFileNumbers, lengthOfSecondFile);

    int *intersectionArray = intersection(arrayOfFirstFileNumbers, lengthOfFirstFile,arrayOfSecondFileNumbers, lengthOfSecondFile, &lengthOfIntersectionArray);
    int *unionArray = unionArrayFunc(arrayOfFirstFileNumbers, lengthOfFirstFile,arrayOfSecondFileNumbers, lengthOfSecondFile, &lengthOfunionArray);
    int *symmDiffArray = difference(unionArray, lengthOfunionArray, intersectionArray, lengthOfIntersectionArray, &lengthOfSymmetricDifferenceArray);
    int *onlyInFirstArray = difference(arrayOfFirstFileNumbers, lengthOfFirstFile,arrayOfSecondFileNumbers, lengthOfSecondFile, &lenOfOnlyInFirstArray);

    arrayToFile(intersectionArray, lengthOfIntersectionArray, intersectionFileName);
    arrayToFile(unionArray, lengthOfunionArray, unionFileName);
    arrayToFile(symmDiffArray, lengthOfSymmetricDifferenceArray, symmDiffFileName);
    arrayToFile(onlyInFirstArray, lenOfOnlyInFirstArray, onlyInTheFirstFile);

    free(arrayOfFirstFileNumbers);
    free(arrayOfSecondFileNumbers);
    free(intersectionArray);
    free(unionArray);
    free(symmDiffArray);
    free(onlyInFirstArray);

    printf("I've done all my work! Check new files!\n");
}
