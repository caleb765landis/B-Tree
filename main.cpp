// main.cpp
#include <iostream>
#include "BTree.h"
#include "Node.h"

using namespace std;

int main() {
  BTree t = BTree(3);

  const int n = 18;
  int k[n] = {3,7,9,23,45,1,5,14,25,24,13,11,8,19,4,39,35,56};


  for (int i = 1; i < n; i++) {
    t.insert(k[i]);
  }


  /*
  t.insert(7);
  t.insert(9);
  t.insert(23);
  t.insert(45);
  t.insert(1);
  t.insert(5);
  t.insert(14);
  t.insert(25);
  t.insert(24);
  t.insert(13);
  t.insert(11);
  t.insert(8);
  t.insert(19);
  t.insert(4);
  t.insert(39);
  t.insert(35);
  t.insert(56);
  */

  for (int x = 0; x < t.root -> length; x++) {
    std::cout << t.root -> keys[x] << ", ";
    //std::cout << temp[x];
  }
  std::cout << std::endl;
}
