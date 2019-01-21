#include <stdlib.h>
#include "binarytree.h"
#include "copybinarytree.h"

tree_type stack[STACKSIZE];
static int sp = -1;

static int empty() {
  return sp == -1;
}

static void push(tree_type node) {
  stack[++sp] = node;
}

static tree_type pop() {
  return stack[sp--];
}

static tree_type top() {
  return stack[sp];
}



tree_type copy_tree_recursive(tree_type tree) {
 if(!tree)
   return NULL;

 tree_type root = malloc(sizeof(struct BTree));
 if(!root)
   exit(1);
 root->vertex = tree->vertex;
 root->left = copy_tree_recursive(tree->left);
 root->right = copy_tree_recursive(tree->right);
 return root;
}


tree_type copy_tree(tree_type tree) {
  tree_type cur = tree;
  tree_type newnode, newbtree, parent = NULL;
  while(cur || !empty()) {
    while(cur) {
      newnode = malloc(sizeof(struct BTree));
      newnode->left = newnode->right = NULL;
      newnode->vertex = cur->vertex;
      push(parent); push(newnode); push(cur);
      parent = newnode;
      cur = cur->left;
    }

    if(!cur) {
      cur = pop();
      newnode = pop();
      parent = pop();
      if(parent) {
        if(parent->vertex >= newnode->vertex) {
          parent->left = newnode;
        } else {
          parent->right = newnode;
        }
      } else {
         newbtree = newnode; // when parent is null. when the binarytree contains only one item.
      }
      parent = newnode;
      cur = cur->right;
    }
  }
  return newbtree;
}
