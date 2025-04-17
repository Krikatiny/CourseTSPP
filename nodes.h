//
// Created by zahar on 16.04.2025.
//

#ifndef NODES_H
#define NODES_H

struct node* insertLeft(struct nodeTree* rootNode, struct node* leftNode);
struct node* insertLeftNewNode(struct nodeTree* rootNode, char name[10]);

struct node* newNode(const char name[10], int importance);
struct node* insertRight(struct nodeTree* rootNode, struct node* rightNode);
struct node* insertRightNewNode(struct nodeTree* rootNode, char name[10]);

struct nodeTree* newNodeTree(struct node* rootNode, char name[10]);
struct nodeTree* newNodeTreeL(struct node* rootNode, struct node* leftNode, char name[10]);
struct nodeTree* newNodeTreeLR(struct node* rootNode, struct node* leftNode, struct node* rightNode, char name[10]);

void printNodeFromBottom(struct nodeTree* inputNode);
void printNodeFromTop(struct nodeTree* inputNode);

struct node;
struct nodeTree;


#endif //NODES_H
