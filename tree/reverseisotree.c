#include <stdio.h>
#include "binarytree.h"
#include "reverseisotree.h"



tree_type reverse_btree_iso(tree_type tree) {
  if(!tree)
    return NULL;
  tree_type tmpleft = tree->left, tmpright = tree->right;
  tree->right = reverse_btree_iso(tmpleft);
  tree->left = reverse_btree_iso(tmpright);
  return tree;
}
