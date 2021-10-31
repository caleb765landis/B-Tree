// Node.cpp

#include "Node.h"

Node::Node() {
  parent = NULL;
  leaf = false;
  length = 0;
} // end constructor

Node::Node(int key, bool isLeaf, Node* newParent) {
  keys[0] = key;
  parent = newParent;
  leaf = isLeaf;
  length = 1;
} // end overloaded constructor

Node::~Node() {
  for (int i = 0; i <= length; i++) {
    delete children[i];
  } // end for
} // end destructor
