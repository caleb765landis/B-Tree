// Node.h

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>

class Node {
  public:
  int keys[6] = {};
  Node* children[7] = {};
  Node* parent;
  bool leaf;
  int length;

  Node();
  Node(int key, bool isLeaf, Node* newParent);
  ~Node();
};
#endif
