// Node.cpp

#include "Node.h"

Node::Node() {
  keys = new int[5];
  children = new Node*[6];
  parent = NULL;
  leaf = false;
  length = 0;
  //hasChildren = false;
}

Node::Node(int key, bool isLeaf, Node* newParent) {
  keys = new int[5];
  keys[0] = key;
  children = new Node*[6];
  parent = newParent;
  leaf = isLeaf;
  length = 1;
  //hasChildren = false;
}

/*
int Node::length() {
  int length = sizeof(&keys)/sizeof(&keys[5]);
  return length;
}
*/
