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

    struct node* root;
    struct node* left;
    struct node* right;
    struct nodeTree* nodeTree;

    clearArr(input);
    clearArr(refactored);
    clearArr(operator);
    clearArr(rightNumber);
    clearArr(leftNumber);

    getInputInArr(input);
    copyArr(input, refactored);
    clearSpaces(refactored);

    pos = getOperationPos(refactored, pos);
    standardOperator(refactored, operator, pos);
    pos = calibratePos(refactored, pos);

    root = newNode(operator, 1);
/*
    searchNumberLeft(refactored, leftNumber, pos);
    left = newNode(leftNumber, 1);
*/
    searchNumberRight(refactored, rightNumber, pos);
    right = newNode(rightNumber, 1);
//    insertLeft(root, left);
    insertRight(root, right);

    printTreeFromTop(root);

    return 0;
}