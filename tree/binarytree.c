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

tree_type insert_bree_recursive(tree_type tree, int data) {
  if(!tree) {
    tree_type new = malloc(sizeof(struct BTree));
    new->right = new->left = NULL;
    new->vertex = data;
  }
  if(tree->vertex <=  data) {
    tree->right = insert_bree_recursive(tree->right, data);
  } else {
    tree->left = insert_bree_recursive(tree->left, data);
  }
  return tree;
}


tree_type search_btree_recursive(tree_type tree, int item) {
  if(!tree ||  tree->vertex == item) {
    return tree;
  }
  if(tree->vertex > item) {
    return search_btree_recursive(tree->left, item);
  } else {
    return search_btree_recursive(tree->right, item);
  }
}

tree_type search_btree_nonrecursive(tree_type tree, int item) {
  tree_type cur = tree;
  tree_type retval = NULL;
  while(cur) {
    if(cur->vertex == item) {
      retval = cur;
      break;
    }
    cur = cur->vertex > item ? cur->left : cur->right;
    }
    return retval;
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
