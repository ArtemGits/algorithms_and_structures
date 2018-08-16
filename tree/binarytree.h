#ifndef BINARYTREE_H
#define BINARYTREE_H
#define STACKSIZE 300

struct BTree {
  int vertex;
  struct BTree* right;
  struct BTree* left;
};

typedef struct BTree* tree_type;

void insert_btree(tree_type *, int);
void infix_recursive(tree_type); 
void prefix_recursive(tree_type);
void suffix_recursive(tree_type);


#endif

