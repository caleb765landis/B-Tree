// BTree.h

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include "Node.h"
#include <vector>

class BTree {
  public:
  Node* root;
  //Node root;

  BTree(int key);
  ~BTree();
  void insert(int key);
  void split(Node* currentNode, int location);
  void print(Node* currentNode);
  void search(Node* currentNode, int n);
  //void print(Node* currentNode);
  //void search(Node* currentNode, int n);
  //void depth(Node* currentNode, int newDepth);
};
#endif
