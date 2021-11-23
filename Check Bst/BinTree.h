#ifndef BINTREE_H
#define BINTREE_H
#include<stdbool.h>

typedef struct no{
  int key;
  struct no *left;
  struct no *right;
  struct no *p;
}TNo;

typedef struct{
  TNo* root;
}BinTree;

TNo* TNo_createNFill(int);
BinTree* BinTree_create();
BinTree* Construct_BinTree(char*, int*);

void BinTree_check(TNo*, BinTree*, int*);
void BinTree_preorder(TNo*);
void BinTree_inorder(TNo*);
void BinTree_posorder(TNo*);

#endif