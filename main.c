#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"





//NODES

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
