
// Node.h

#include <string>
#include <vector>
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node {
  public:
  //int* keys;
  Node* children[7] = {};
  //std::vector<int> keys{std::vector<int>(5,0)};
  int keys[6] = {};
  //std::vector<int> keys;
  //std::vector<Node*> children;
  //std::vector<Node*> children = std::vector<Node*>(6, NULL);
  Node* parent;
  bool leaf;
  int length;
  //int numChildren;

  Node();
  Node(int key, bool isLeaf, Node* newParent);
  ~Node();
  //void Print();
  //int length();
};
#endif
