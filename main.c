#include <stdio.h>
#include "arithmetics.h"


int main()
{
    int pos = 0;
    int standardOperation = TRUE;
    char input[100] = " ";
    char numberRight[100] = " ";
    char numberLeft[100] = " ";
    char operation[100] = " ";
    char refactoredInput[100] = " ";
    int length = 0;
    clearArr(input);
    clearArr(numberRight);
    clearArr(operation);
    clearArr(numberLeft);
    clearArr(refactoredInput);

    getInputInArr(input);
    copyArr(input, refactoredInput);
    clearSpaces(refactoredInput);


    pos = getOperationPos(refactoredInput, pos);
    if (searchOperator(refactoredInput, operation, pos))
    {
        standardOperation = TRUE;
    }
    else
    {
        standardOperation = FALSE;
        pos += 3;
    }

    if (standardOperation == TRUE)
    {
        searchNumberLeft(refactoredInput, numberLeft, pos);
        printf("%s - ", numberLeft);
        searchNumberRight(refactoredInput, numberRight, pos);
        printf("%s", operation);
        printf(" - %s", numberRight);
        pos++;
    }
    else
    {
        printf("%s", operation);
        pos--;
        searchNumberRight(refactoredInput, numberRight, pos);
        pos++;
        printf(" - %s", numberRight);
        pos++;
    }
    length = getLength(refactoredInput);
    if (pos < length)
    {
        for (int i = pos; i < length; i++)
        {
            pos = getOperationPos(refactoredInput, pos);
            searchOperator(refactoredInput, operation, pos);
            printf(" - %s", operation);
            searchNumberRight(refactoredInput, numberRight, pos);
            printf(" - %s", numberRight);
            pos++;
            i = pos;
        }
    }
    return 0;
}

