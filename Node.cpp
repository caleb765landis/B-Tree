// Node.cpp

#include <iostream>
using namespace std;

#include "Node.h"

Node::Node() {
  keys = new int[5];
  children = new Node*[5];
  // n = 0;
  leaf = false;
}

int main() {
  Node* test = new Node();
  test -> keys[0] = 1;
  cout << test -> keys[0] << endl;

  Node* child = new Node();
  child -> keys[0] = 2;
  test -> children[0] = child;
  cout << test -> children[0] -> keys[0] << endl;
}
