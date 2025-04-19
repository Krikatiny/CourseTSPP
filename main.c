#include <stdio.h>
#include <stdlib.h>

#include "arithmetics.h"
#include "nodes.h"


int main()
{
    FILE* file;
    file = fopen("input.gv", "w");
    fprintf(file, "graph G{\n");
    fclose(file);
    char input[100];
    char refactored[100];
    char operator[100];
    char rightNumber[100];
    char leftNumber[100];
    int nodePos = 0;
    int pos = 0;
    int length = 0;
    int nodeChange = 0;

    struct node* nodes[100];
    int latestOperationNodeNum = 0;
    int nodesAdded = 0;
    clearArr(input);
    clearArr(refactored);
    clearArr(operator);
    clearArr(rightNumber);
    clearArr(leftNumber);

    getInputInArr(input);
    copyArr(input, refactored);
    clearSpaces(refactored);

    length = getLength(refactored);

    struct node* node1 = newNode("1", 0);
    struct node* node2 = newNode("+", 1);
    struct node* node3 = newNode("2", 2);
    struct node* node4 = newNode("*", 3);
    struct node* node5 = newNode("3", 4);
    struct node* node6 = newNode("+", 5);
    struct node* node7 = newNode("4", 6);

    //+ -- 1
    addLeftNode(node2, node1);
    //+ -- 2
    addRightNode(node2, node3);
    //* -- +
    addRightNode(node4, node2);
    //* -- 3
    addLeftNode(node4, node5);
    //+ -- *
    addRightNode(node6, node4);
    //+ -- 4
    addLeftNode(node6, node7);
    nodes[0] = node1;
    nodes[1] = node2;
    nodes[2] = node3;
    nodes[3] = node4;
    nodes[4] = node5;
    nodes[5] = node6;
    nodes[6] = node7;

    while (length > 0)
    {
        nodesAdded = 0;
        if (getOperationPos(refactored, pos) == -1)
        {
            searchNumberRight(refactored, rightNumber, pos);
            nodes[nodePos] = newNode(rightNumber, nodeChange);
            nodeChange++;
            nodes[latestOperationNodeNum]->right = nodes[nodePos];
            nodes[nodePos]->root = nodes[latestOperationNodeNum];
            break;
        }
        pos = getOperationPos(refactored, pos);
        getOperator(refactored, operator, pos);
        nodes[nodePos] = newNode(operator, nodeChange);
        nodeChange++;
        nodesAdded++;
        if (nodePos != 0)
        {
            if (nodes[latestOperationNodeNum]->right == NULL)
            {
                nodes[nodePos]->root = nodes[latestOperationNodeNum];
                nodes[latestOperationNodeNum]->right = nodes[nodePos];
            }
            else
            {
                nodes[latestOperationNodeNum]->root = nodes[nodePos];
            }
        }
        latestOperationNodeNum = nodePos;


        //Operator check
        if (standardOperator(operator, 0) == TRUE)
        {
            searchNumberLeft(refactored, leftNumber, pos);
            if (getLength(leftNumber) != 0)
            {
                nodes[nodePos + 1] = newNode(leftNumber, nodeChange);
                nodeChange++;
                nodesAdded++;
                addLeftNode(nodes[nodePos], nodes[nodePos + 1]);
            }
            if (getOperationPos(refactored, pos) == -1)
            {
                searchNumberRight(refactored, rightNumber, pos);
                nodes[nodePos + 2] = newNode(rightNumber, nodeChange);
                nodeChange++;
                nodesAdded++;
                addRightNode(nodes[nodePos], nodes[nodePos + 2]);
            }
            nodePos = nodePos + nodesAdded;
        }
        else
        {
            pos = pos + getLength(operator) - 1;
            nodePos = nodePos + nodesAdded;
        }
        importanceTest(nodes[latestOperationNodeNum]);
    }
    printNodeFromTop(nodes[0], file);
    file = fopen("input.gv", "ab+");
    fprintf(file, "}");
    fclose(file);
    system("command.bat");
    system("explorer.exe file.png");
    return 0;
}
