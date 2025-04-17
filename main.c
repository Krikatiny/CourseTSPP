#include <stdio.h>
#include <stdlib.h>

#include "arithmetics.h"
#include "nodes.h"


int main()
{
    char input[100];
    char refactored[100];
    char operator[100];
    char rightNumber[100];
    char leftNumber[100];
    int pos = 0;
    int length = 0;

    struct node* root;
    struct node* temp;

    clearArr(input);
    clearArr(refactored);
    clearArr(operator);
    clearArr(rightNumber);
    clearArr(leftNumber);

    getInputInArr(input);
    copyArr(input, refactored);
    clearSpaces(refactored);

    pos = getOperationPos(refactored, pos);
    getOperator(refactored, operator, pos);
    root = newNode(operator, 1);
    length = getLength(refactored);


    if (standardOperator(refactored, operator, pos) == TRUE)
    {
        searchNumberLeft(refactored, leftNumber, pos);
        addLeftNode(root, newNode(leftNumber, 1));
    }

    while (pos < length)
    {
        if (standardOperator(refactored, operator, pos) == TRUE)
        {
            pos = calibratePos(refactored, pos);
        }

        searchNumberRight(refactored, rightNumber, pos);
        addRightNode(root, newNode(rightNumber, 1));
        pos++;
    }
    printNodeFromTop(root);

    return 0;
}