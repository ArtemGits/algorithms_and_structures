#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"


void insert_btree(tree_type* tree, int data) {
  tree_type node = malloc(sizeof(struct BTree));
  tree_type current = *tree;
  tree_type parrent = NULL;
  node->vertex = data;
  node->left = node->right = NULL;

  if(!current) {
    *tree = node;
    return;
  }
  //find place
  while(current) {
    parrent = current;
    if(current->vertex >= data) {
      current = current->right;
    } else {
      current = current->left;
    }
  }
  if(parrent->vertex >= data) {
    parrent->right = node;
  } else {
    parrent->left = node;
  }
}


void infix_recursive(tree_type root) {
  if(root) {
    infix_recursive(root->left);
    printf("%d ", root->vertex);
    infix_recursive(root->right);
  }
}

void prefix_recursive(tree_type root){
	if(root){
		printf("%d ",root->vertex );
		prefix_recursive(root->left);
		prefix_recursive(root->right);
	}
}


void suffix_recursive(tree_type root){
	if(root){
		suffix_recursive(root->left);
		suffix_recursive(root->right);
		printf("%d ",root->vertex );
	}
}
