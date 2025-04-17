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
    int nodePos = 0;
    int pos = 0;
    int length = 0;


    struct node* nodes[100];

    clearArr(input);
    clearArr(refactored);
    clearArr(operator);
    clearArr(rightNumber);
    clearArr(leftNumber);

    getInputInArr(input);
    copyArr(input, refactored);
    clearSpaces(refactored);

    length = getLength(refactored);

    pos = getOperationPos(refactored, pos);
    getOperator(refactored, operator, pos);
    nodes[1] = newNode(operator);

    if (standardOperator(refactored, pos) == TRUE)
    {
        searchNumberLeft(refactored, leftNumber, pos);
        nodes[0] = newNode(leftNumber);
        addLeftNode(nodes[1], nodes[0]);
    }
    else
    {
        pos = calibratePos(refactored, pos);
    }

    if (getOperationPos(refactored, pos + 1) != pos + 1)
    {
        pos = searchNumberRight(refactored, rightNumber, pos);
        nodes[2] = newNode(rightNumber);
        addRightNode(nodes[1], nodes[2]);
    }
    else
    {
        pos = getOperationPos(refactored, pos + 1);
        getOperator(refactored, operator, pos);
        nodes[2] = newNode(operator);
        addRightNode(nodes[1], nodes[2]);
    };
    if (getOperationPos(refactored, pos) == pos)
    {
        pos = calibratePos(refactored, pos);
    }
    else
    {
        pos = getOperationPos(refactored, pos);
    }

    nodePos = nodePos + 3;

    while (pos < length - 1)
    {
        getNumber(refactored, rightNumber, pos);
        if (getOperator(refactored, operator, pos) == -1)
        {
            break;
        }
        if (standardOperator(refactored, pos) == TRUE)
        {
            nodes[nodePos] = newNode(operator);
            searchNumberRight(refactored, rightNumber, pos);
            pos = getOperationPos(refactored, pos + 1);
            nodes[nodePos + 1] = newNode(rightNumber);
            addRightNode(nodes[nodePos], nodes[nodePos + 1]);
            addLeftNode(nodes[nodePos], nodes[nodePos - 2]);
            nodePos = nodePos + 2;
        }

        else
        {
            pos = getOperationPos(refactored, pos);
            getOperator(refactored, operator, pos);
            nodes[nodePos] = newNode(operator);
            searchNumberRight(refactored, rightNumber, pos);
            pos = getOperationPos(refactored, pos);
            nodes[nodePos + 1] = newNode(rightNumber);
            nodePos = nodePos + 2;
        }
    }
    printNodeFromTop(nodes[1]);
    return 0;
}
