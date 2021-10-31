// Node.cpp

#include "Node.h"


Node::Node() {
  //keys = new int[5] {};
  //children = new Node*[5];
  //keys = new std::vector<int>;
  //children = new std::vector<Node*>;
  //fill(keys.begin(),keys.end(),0);
  parent = NULL;
  leaf = false;
  length = 0;
  //numChildren = 0;
}

Node::Node(int key, bool isLeaf, Node* newParent) {
  //keys = new std::vector<int>;
  //children = new std::vector<Node*>;
  //keys = new int[5] {};
  //fill(keys.begin(),keys.end(),0);
  //keys.at(0) = key;
  keys[0] = key;
  //children = new Node*[6];
  parent = newParent;
  leaf = isLeaf;
  length = 1;
  //numChildren = 0;
}

Node::~Node() {

  for (int i = 0; i <= length; i++) {
    delete children[i];
  } // end for

  //delete[] keys;
  //delete[] children;
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
