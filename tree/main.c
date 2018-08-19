#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"


void search_test(tree_type tree, int target) {
  tree_type node = search_btree_recursive(tree, target);
  printf("Search recursive\n");
  if(!node) {
    printf("Found\n");
  } else {
    printf("Not found\n");
  }
}

int main() {
  
  int data[] = {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(data)/sizeof(int);
  tree_type btree = NULL;
  int i = 0;
  while( i < size) {
    insert_btree(&btree, data[i++]);
  }
  //TODO fix implementation for non found nodes, becouse that doesn't work 
  search_test(btree, 11);
 
 // infix_recursive(btree);
 // printf("\n");
 // prefix_recursive(btree);
 // printf("\n");
 // suffix_recursive(btree);
  return 0;
}
