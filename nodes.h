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

void addLeftNode(struct node* rootNode, struct node* leftNode);
void addLeftNewNode(struct node* rootNode, char name[10]);

struct node* newNode(const char name[10]);
void addRightNode(struct node* rootNode, struct node* rightNode);
void addRightNewNode(struct node* rootNode, char name[10]);

void printNode(struct node* node);

void addRoot(struct node* node, struct node* root);
int setImportance(struct node* rootNode);

void printNodeFromBottom(struct node* node);
void printNodeFromTop(struct node* node);

#endif //NODES_H
