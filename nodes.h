//
// Created by zahar on 16.04.2025.
//

#ifndef NODES_H
#define NODES_H


struct node
{
    char name[10];
    int importance;
    struct node* root;
    struct node* left;
    struct node* right;
};

void insertLeft(struct node* rootNode, struct node* leftNode);
void insertLeftNewNode(struct node* rootNode, char name[10]);

struct node* newNode(const char name[10], int importance);
void insertRight(struct node* rootNode, struct node* rightNode);
void insertRightNewNode(struct node* rootNode, char name[10]);

void printNodeFromBottom(struct node* node);
void printTreeFromTop(struct node* node);


#endif //NODES_H
