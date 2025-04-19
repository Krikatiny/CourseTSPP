//
// Created by zahar on 16.04.2025.
//

#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arithmetics.h"


struct node* newNode(const char name[10], int num)
{
    struct node* new_node = calloc(1, sizeof(struct node));
    for (int i = 0; i < 9; i++)
    {
        new_node->name[i] = ' ';
    }
    for (int i = 0; i < 9; i++)
    {
        new_node->name[i] = name[i];
    }

    new_node->importance = setImportance(new_node);
    new_node->num = num;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int setImportance(struct node* node)
{
    if (node == NULL)
        return -1;

    if (node->name[0] == '+' || node->name[0] == '-')
    {
        return 1;
    }

    if (node->name[0] == '*' || node->name[0] == '/' || node->name[0] == '%' || node->name[0] == 's' || node->name[0] == 't' || node->name[0] == 'c')
    {
        return 2;
    }
    if (node->name[0] == '^')
    {
        return 3;
    }
    return 10;
}

void printNodeFromBottom(struct node* node)
{
    if (node == NULL)
    {
        return;
    }
    printNodeFromBottom(node->left);
    printNodeFromBottom(node->right);
    printf("%s -> ", node->name);
}

void printNodeFromTop(struct node* node, FILE* file)
{
    if (node == NULL)
    {
        return;
    }
    if (node->root == NULL)
    {
        printNode(node->left, file);
        printNode(node->right, file);
    }
    else
    {
        printNodeFromTop(node->root, file);
    }
}

void printNode(struct node* node, FILE* file)
{
    if (node == NULL)
    {
        return;
    }
    file = fopen("input.gv", "ab+");
    char table[52] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    // %s[label=\"\"%s\"\"]\n - table[node->num]
    fprintf(file, "%c[label=\"%s\"]\n", table[node->root->num], node->root->name);
    fprintf(file, "%c[label=\"%s\"]\n", table[node->num], node->name);
    fprintf(file, "%c -- %c\n", table[node->root->num], table[node->num]);
    if (node->left != NULL)
    {
        printNode(node->left, file);
    }
    if (node->right != NULL)
    {
        printNode(node->right, file);
    }
    fclose(file);
}

void addRightNode(struct node* rootNode, struct node* rightNode)
{
    rootNode->right = rightNode;
    rightNode->root = rootNode;
}

void addLeftNode(struct node* rootNode, struct node* leftNode)
{
    rootNode->left = leftNode;
    leftNode->root = rootNode;
}

void addRoot(struct node* node, struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    node->root = root;
    if (root->left == NULL)
    {
        root->left = node;
    }
    if (root->right == NULL)
    {
        root->right = node;
    }
}

int importanceTest(struct node* root)
{
    if (root == NULL) { return; }

    if (root->left != NULL)
    {
        if (root->importance < root->left->importance)
        {
            char name[100];
            clearArr(name);
            copyArr(root->name, name);
            copyArr(root->left->name, root->name);
            copyArr(name, root->left->name);
            return 0;
        }
    }
    if (root->right != NULL)
    {
        if (root->importance < root->right->importance)
        {
            char name[100];
            clearArr(name);
            copyArr(root->name, name);
            copyArr(root->right->name, root->name);
            copyArr(name, root->right->name);
            return 0;
        }
    }
    return 1;
}
