//
// Created by zahar on 16.04.2025.
//

#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>



struct node
{
    char name[10];
    int importance;
};

struct nodeTree
{
    char name[10];
    struct node* root;
    struct node* left;
    struct node* right;
};

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

    return new_node;
}

struct nodeTree* newNodeTree(struct node* rootNode, char name[10])
{
    struct nodeTree* newNodeTree = calloc(1, sizeof(struct nodeTree));
    newNodeTree->root = rootNode;
    return newNodeTree;
}

struct nodeTree* newNodeTreeL(struct node* rootNode, struct node* leftNode, char name[10])
{
    struct nodeTree* newNodeTree = calloc(1, sizeof(struct nodeTree));
    newNodeTree->root = rootNode;
    newNodeTree->left = leftNode;
    return newNodeTree;
}

struct nodeTree* newNodeTreeLR(struct node* rootNode, struct node* leftNode, struct node* rightNode, char name[10])
{
    struct nodeTree* newNodeTree = calloc(1, sizeof(struct nodeTree));
    newNodeTree->root = rootNode;
    newNodeTree->left = leftNode;
    newNodeTree->right = rightNode;
    return newNodeTree;
}

void printNodeFromBottom(struct nodeTree* inputNode)
{
    if (inputNode == NULL)
    {
        return;
    }
    printNodeFromBottom(inputNode->left->name);
    printNodeFromBottom(inputNode->right->name);
    printf("%s -> ", inputNode->root->name);
}

void printNodeFromTop(struct nodeTree* inputNode)
{
    if (inputNode == NULL)
    {
        return;
    }
    printf("%s -> ", inputNode->root->name);
    printNodeFromTop(inputNode->left->name);
    printNodeFromTop(inputNode->right->name);
}


struct node* insertRightNewNode(struct nodeTree* rootNode, char name[10])
{
    //TODO CHANGE IMPORTANCE

    rootNode->right = newNode(name, 1);
    return rootNode->right;
}

struct node* insertRight(struct nodeTree* rootNode, struct node* rightNode)
{
    rootNode->right = rightNode;
    return rootNode->right;
}

struct node* insertLeftNewNode(struct nodeTree* rootNode, char name[10])
{
    //TODO CHANGE IMPORTANCE
    rootNode->left = newNode(name, 1);
    return rootNode->left;
}

struct node* insertLeft(struct nodeTree* rootNode, struct node* leftNode)
{
    rootNode->left = leftNode;
    return rootNode->left;
}
