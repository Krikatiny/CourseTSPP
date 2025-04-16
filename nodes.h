//
// Created by zahar on 16.04.2025.
//

#ifndef NODES_H
#define NODES_H
struct node* insertLeft(struct node* inputNode, struct node* newNode);
struct node* insertLeftNewNode(struct node* inputNode, char name[10]);

struct node* newNode(const char name[10]);
struct node* insertRight(struct node* inputNode, struct node* newNode);
struct node* insertRightNewNode(struct node* inputNode, char name[10]);

void printNodeFromBottom(struct node* inputNode);
void printNodeFromTop(struct node* inputNode);
struct node
{
    char name[10];
    struct node* left;
    struct node* right;
};
#endif //NODES_H
