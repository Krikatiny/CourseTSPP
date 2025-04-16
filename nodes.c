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


struct node* insertRightNewNode(struct node* rootNode, char name[10])
{
    rootNode->right = newNode(name);
    return rootNode->right;
}

struct node* insertRight(struct node* rootNode, struct node* rightNode)
{
    rootNode->right = rightNode;
    return rootNode->right;
}

struct node* insertLeftNewNode(struct node* rootNode, char name[10])
{
    rootNode->left = newNode(name);
    return rootNode->left;
}

struct node* insertLeft(struct node* rootNode, struct node* leftNode)
{
    rootNode->left = leftNode;
    return rootNode->left;
}
