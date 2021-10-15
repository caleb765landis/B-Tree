// Node.h

#include <string>
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node {
  public:
  int* keys;
  Node** children;
  Node* parent;
  bool leaf;
  int length;

  Node();
  Node(int key, bool isLeaf, Node* parent);
  //int length();
};
#endif
