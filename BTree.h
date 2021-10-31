// BTree.h

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <iostream>
#include "Node.h"

class BTree {
  public:
  Node* root;

  BTree(int key);
  ~BTree();
  void insert(int key);
  void split(Node* currentNode);
  void print(Node* currentNode);
  void search(Node* currentNode, int n);
};
#endif
