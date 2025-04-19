//
// Created by zahar on 16.04.2025.
//

#ifndef NODES_H
#define NODES_H
#include <stdio.h>


struct node
{
    char name[10];
    int importance;
    int num;
    struct node* root;
    struct node* left;
    struct node* right;
};

void addLeftNode(struct node* rootNode, struct node* leftNode);

struct node* newNode(const char name[10], int num);
void addRightNode(struct node* rootNode, struct node* rightNode);

void printNode(struct node* node, FILE* file);

void addRoot(struct node* node, struct node* root);
int setImportance(struct node* rootNode);
int importanceTest(struct node* root);

void printNodeFromBottom(struct node* node);
void printNodeFromTop(struct node* node, FILE* file);

#endif //NODES_H
