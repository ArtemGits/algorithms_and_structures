#ifndef BINARYTREE_H
#define BINARYTREE_H
#define STACKSIZE 300

struct BTree {
  int vertex;
  struct BTree* right;
  struct BTree* left;
};

typedef struct BTree* tree_type;

void insert_btree(tree_type*, int);
tree_type insert_bree_recursive(tree_type, int);

tree_type search_btree_recursive(tree_type, int);
tree_type search_btree_nonrecursive(tree_type, int);

void infix_recursive(tree_type); 
void prefix_recursive(tree_type);
void suffix_recursive(tree_type);

void infix_nonrecursive(tree_type);
void prefix_nonrecursive(tree_type);
void suffix_nonerecursive(tree_type);

void delete_btree(tree_type*, int);
void destroy_btee(tree_type);

#endif

