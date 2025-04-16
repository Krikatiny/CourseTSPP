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

    clearArr(input);
    clearArr(refactored);
    clearArr(operator);
    clearArr(rightNumber);
    clearArr(leftNumber);

    getInputInArr(input);
    copyArr(input, refactored);
    clearSpaces(refactored);

    pos = getOperationPos(refactored, pos);
    identifyOperator(refactored, operator, pos);
    root = newNode(operator);
    searchNumberLeft(refactored, leftNumber, pos);
    left = newNode(leftNumber);
    searchNumberRight(refactored, rightNumber, pos);
    right = newNode(rightNumber);
    insertLeft(root, left);
    insertRight(root, right);

    printNodeFromTop(root);

    return 0;
}