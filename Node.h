// Node.h

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node {
  public:
  int* keys;
  Node** children;
  // int n;
  bool leaf;

  Node();
};
#endif
