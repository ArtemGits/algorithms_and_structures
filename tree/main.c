#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"


int main() {
  
  int data[] = {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(data)/sizeof(int);
  tree_type btree = NULL;
  int i = 0;
  while( i < size) {
    insert_btree(&btree, data[i++]);
  }
  
  infix_recursive(btree);
  printf("\n");
  prefix_recursive(btree);
  printf("\n");
  suffix_recursive(btree);
  return 0;
}
