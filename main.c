#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NODES
struct node
{
  char name[10];
  struct node* left;
  struct node* right;
};

struct node* newNode(char name[10])
{
  struct node* new_node;
  new_node = malloc(sizeof(struct node));
  for (int i = 0; new_node->name[i]; i++)
  {
    new_node->name[i] = ' ';
  }
  for (int i = 0; new_node->name[i]; i++)
  {
    new_node->name[i] = name[i];
  }
  new_node->left = NULL;
  new_node->right = NULL;
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


struct node* insertRight(struct node* inputNode, char name[10])
{
  inputNode->right = newNode(name);
  return inputNode->right;
}

struct node* insertLeft(struct node* inputNode, char name[10])
{
  inputNode->left = newNode(name);
  return inputNode->left;
}

//ARITHMETIC

//TODO Make ARITHMETIC WORKS

//MAIN
int main(void)
{
  struct node* myNode = newNode("1");
  struct node* myNodeRight = insertRight(myNode, "R1");
  struct node* myNodeLeft = insertLeft(myNode, "L1");
  struct node* myNodeLeft1 = insertLeft(myNodeLeft, "L2");
  struct node* myNodeLeft2 = insertLeft(myNodeLeft1, "L3");
  struct node* myNodeLeft3 = insertLeft(myNodeLeft2, "L4");
  struct node* myNodeLeft4 = insertRight(myNodeLeft3, "R2");


  printNodeFromBottom(myNode);
  printf("\n");
  printNodeFromTop(myNode);
  return 0;
}
