#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree* BinTree_create(){
  BinTree* tree = malloc(sizeof(BinTree));
  if(tree != NULL){
    tree->root = NULL;
  }return tree;
}

TNo* Tno_createNFill(char *string, int *number) {
  if (string[*number + 1] == ')'){
    *number = *number + 1;
    return NULL;
  } 
  else{
    int X = *number + 1;
    while (string[X] != '(' && string[X] != ')') X++;
    char* nstring = malloc(sizeof(char) * (X- *number -1));
    
    for (int i=1; i<=X -*number-1; i++) 
      nstring[i-1] = string[*number+i];
  
    int n = atoi(nstring);
    free(nstring);

    TNo* node = malloc(sizeof(TNo));
    if(node != NULL) {
      node->p = NULL;
      node->left = NULL;
      node->right = NULL;
      node->key = n;
    }
    *number += X - *number;
    return node;
  }
}

void BinTree_check(TNo* root, BinTree* tree, int* check){
  if(root != NULL){
    if(root->left != NULL)
      if(root->key > root->left->key)
        BinTree_check(root->left, tree, check);
      else
       *check += 1;

    if(root->right != NULL)
      if(root->key < root->right->key)
        BinTree_check(root->right, tree, check);
      else
        *check += 1;
  }
  if(*check != 0)
    printf("notBst\n");
  else if(root == tree->root) printf("bst\n");
}

void BinTree_preorder(TNo* root){
  if(root != NULL){
    printf(" %d,", root->key);
    BinTree_preorder(root->left);
    BinTree_preorder(root->right);
  }
}

void BinTree_inorder(TNo* root){
  if(root != NULL){
    BinTree_inorder(root->left);
    printf(" %d,", root->key);
    BinTree_inorder(root->right);
  }
}

void BinTree_postorder(TNo* root){
  if(root != NULL){
    BinTree_inorder(root->left);
    BinTree_inorder(root->right);
    printf("%d, ", root->key); 
  }
}

BinTree* Construct_BinTree(char *string, int* number) {
  BinTree* tree = malloc(sizeof(BinTree));

  if(tree != NULL)
    tree->root = NULL;
  tree->root = Tno_createNFill(string, number);

  if(string[*number] == '(') {
    BinTree* Tleft = Construct_BinTree(string, number);
    if(Tleft != NULL) 
      tree->root->left = Tleft->root;
    BinTree* Tright = Construct_BinTree(string, number);
    if(Tleft != NULL) 
      tree->root->right = Tright->root;
  }

  *number = *number + 1;
  return tree;
} 
