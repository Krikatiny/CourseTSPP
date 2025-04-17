//
// Created by zahar on 16.04.2025.
//

#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>


struct node* newNode(const char name[10], int importance)
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

    new_node->importance = importance;

    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
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

void printNodeFromTop(struct node* node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%s -> ", node->name);
    printNodeFromTop(node->left);
    printNodeFromTop(node->right);
}

void printNode(struct node* node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%s -> ", node->name);
}


void addRightNewNode(struct node* rootNode, char name[10])
{
    struct node* new_node = newNode(name, 1);
    rootNode->right = new_node;
    new_node->root = rootNode;
}

void addRightNode(struct node* rootNode, struct node* rightNode)
{
    rootNode->right = rightNode;
    rightNode->root = rootNode;
}

void addLeftNewNode(struct node* rootNode, char name[10])
{
    struct node* new_node = newNode(name, 1);
    rootNode->left = new_node;
    new_node->root = rootNode;
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