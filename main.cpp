// main.cpp
#include <iostream>
#include "BTree.h"
#include "Node.h"

using namespace std;

int main() {
  /*
  Node* test = new Node();
  test -> keys[0] = 1;
  cout << test -> keys[0] << endl;

  Node* child = new Node();
  child -> keys[0] = 2;
  test -> children[0] = child;
  cout << test -> children[0] -> keys[0] << endl;
  */

  BTree t = BTree(3);
  //cout << t.root -> keys[0] << endl;
  //cout << t.root -> length() << endl;

  /*
  if (t.root -> leaf == true) {
    cout << "true" << endl;
  }
  */

  t.insert(7);
  t.insert(9);
  t.insert(23);
  t.insert(45);

  for (int x = 0; x < t.root -> length; x++) {
    std::cout << t.root -> keys[x] << ", ";
    //std::cout << temp[x];
  }
  std::cout << std::endl;

  for (int x = 0; x < t.root -> children[0] -> length; x++) {
    std::cout << t.root -> children[0] -> keys[x] << ", ";
    //std::cout << temp[x];
  }
  std::cout << std::endl;

  for (int x = 0; x < t.root -> children[1] -> length; x++) {
    std::cout << t.root -> children[1] -> keys[x] << ", ";
    //std::cout << temp[x];
  }
  std::cout << std::endl;

  //std::cout << t.root -> keys[0] << std::endl;
}
