#include "BinTree.h"
#include <stdio.h>

void PrintTree(BinTree* tree){
  printf("PREORDER:");
  BinTree_preorder(tree->root);
  printf("\nINORDER:");
  BinTree_inorder(tree->root);
  printf("\nPOSORDER:");
  BinTree_posorder(tree->root);
  putchar('\n');
}

int main(){
  char string[4096];
  int number = 0;

  gets(string);
  BinTree* tree = Construct_BinTree(string, &number);
  PrintTree(tree);
  return 0;
}