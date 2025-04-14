#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node* insertLeft(struct node* inputNode, struct node* newNode);
struct node* insertLeftNewNode(struct node* inputNode, char name[10]);

struct node* insertRight(struct node* inputNode, struct node* newNode);
struct node* insertRightNewNode(struct node* inputNode, char name[10]);

//NODES
struct node
{
  char name[10];
  struct node* left;
  struct node* right;
};


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



//ARITHMETIC

//TODO Make ARITHMETIC WORKS

//MAIN
int main(void)
{
  struct node* nodes[10];
  char name[10] = "Hello ";
  for (int i = 0; i < 10; i++)
  {
    name[5] = i + '0';
    nodes[i] = newNode(name);
  }

  insertRight(nodes[0], nodes[1]);
  insertLeft(nodes[0], nodes[2]);
  insertRight(nodes[1], nodes[3]);
  insertLeft(nodes[1], nodes[4]);
  insertRight(nodes[2], nodes[5]);
  insertLeft(nodes[6], nodes[0]);
  printNodeFromTop(nodes[6]);
  printf("\n");
  return 0;
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
