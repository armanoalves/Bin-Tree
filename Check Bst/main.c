#include "BinTree.h"
#include <stdio.h>

int main(){
  char string[4096];
  int number = 0, check = 0;

  gets(string);
  BinTree* tree = Construct_BinTree(string, &number);
  BinTree_check(tree->root, tree, &check);
  return 0;
}