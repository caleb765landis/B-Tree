// BTree.h

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include "Node.h"

class BTree {
  public:
  Node* root;

  BTree(int key);
  void insert(int key);
  void split(Node* currentNode, int location);
};
#endif
