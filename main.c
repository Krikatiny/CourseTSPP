#include <stdio.h>
#include <stdlib.h>

#include "arithmetics.h"
#include "nodes.h"


int main()
{
    FILE *file;
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

    /*  1 + sin2
     *  1+2+3+4
     *  sin2 + 1
     *  1. Очищаємо масив від зайвого
     *  2. Заходимо в масив та шукаємо оператор
     *  3. Створюємо для нього ноду
     *  4. Якщо це бінарний оператор, то шукаємо ліворуч число та праворуч.
     *  5. Якщо праворуч знаходиться не число, то треба визначити той оператор
     *  6. Якщо це унарний, то створюємо для нього ноду та шукаємо праворуч
     *  6. Якщо це унарний, то шукаємо праворуч число
     *  7. Переходимо до точки правого числа
     *  8.
     */

    while (length > 0)
    {
        nodesAdded = 0;
        if (getOperationPos(refactored, pos) == -1)
        {
            searchNumberRight(refactored, rightNumber, pos);
            nodes[nodePos] = newNode(rightNumber,nodeChange);
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
        length = getLengthWithoutSpaces(refactored);
    }
    printNodeFromTop(nodes[0], file);
    file = fopen("input.gv", "ab+");
    fprintf(file, "}");
    fclose(file);
    return 0;
}
