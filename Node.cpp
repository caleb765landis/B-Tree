// Node.cpp

#include "Node.h"

Node::Node() {
  keys = new int[5];
  children = new Node*[5];
  parent = NULL;
  length = false;
  length = 0;
}

Node::Node(int key, bool isLeaf) {
  keys = new int[5];
  keys[0] = key;
  children = new Node*[5];
  parent = NULL;
  leaf = isLeaf;
  length = 1;
}

/*
int Node::length() {
  int length = sizeof(&keys)/sizeof(&keys[5]);
  return length;
}
*/
