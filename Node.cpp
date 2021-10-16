// Node.cpp

#include "Node.h"

Node::Node() {
  keys = new int[5];
  children = new Node*[5];
  parent = NULL;
  leaf = false;
  length = 0;
  //numChildren = 0;
  hasChildren = false;
}

Node::Node(int key, bool isLeaf, Node* newParent) {
  keys = new int[5];
  keys[0] = key;
  children = new Node*[6];
  parent = newParent;
  leaf = isLeaf;
  length = 1;
  //numChildren = 0;
  hasChildren = false;
}

/*
void Node::print() {
  for (int i = 0; i < currentNode -> length; i++) {
    if (currentNode -> leaf == false) {
       currentNode -> children[i] -> print();
    }
    std::cout << currentNode -> keys[i] << ", ";
  }

  if (currentNode -> leaf == false) {
    currentNode -> children[currentNode -> length] -> print();
  }
}

/*
int Node::length() {
  int length = sizeof(&keys)/sizeof(&keys[5]);
  return length;
}
*/
