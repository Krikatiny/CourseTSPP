//
// Created by zahar on 16.04.2025.
//

#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>

struct node* newNode(const char name[10])
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
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void printNodeFromBottom(struct node* inputNode)
{
    if (inputNode == NULL)
    {
        return;
    }
    printNodeFromBottom(inputNode->left);
    printNodeFromBottom(inputNode->right);
    printf("%s -> ", inputNode->name);
}

void printNodeFromTop(struct node* inputNode)
{
    if (inputNode == NULL)
    {
        return;
    }
    printf("%s -> ", inputNode->name);
    printNodeFromTop(inputNode->left);
    printNodeFromTop(inputNode->right);
}


struct node* insertRightNewNode(struct node* inputNode, char name[10])
{
    inputNode->right = newNode(name);
    return inputNode->right;
}

struct node* insertRight(struct node* inputNode, struct node* newNode)
{
    inputNode->right = newNode;
    return inputNode->right;
}

struct node* insertLeftNewNode(struct node* inputNode, char name[10])
{
    inputNode->left = newNode(name);
    return inputNode->left;
}

struct node* insertLeft(struct node* inputNode, struct node* newNode)
{
    inputNode->left = newNode;
    return inputNode->left;
}
