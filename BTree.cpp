// BTree.cpp

#include "Node.h"
#include "BTree.h"
#include <iostream>

BTree::BTree(int key) {
  root = new Node(key, true, NULL);
}

void BTree::insert(int key) {
  bool keepGoing = true;
  Node* currentNode = root;
  int location = 0;

  // find location of where key will be placed or
  // which child is going to have new key
  for (int i = 0; i < currentNode -> length; i++) {
    if (currentNode -> keys[i] < key) {
      location = i + 1;
    } // end if
  } // end for

  while (keepGoing) {
    // if currentNode is a leaf
    if (currentNode -> leaf == true) {
      /*
      // find location where key will be placed
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] < key) {
          location = i + 1;
        }  // end if
      } // end for
      */

      // shift elements forward
      for (int j = currentNode -> length; j >= location; j--) {
         currentNode -> keys[j] = currentNode -> keys[j - 1];
      }

      // insert key into correct position in keys
      currentNode -> keys[location] = key;
      currentNode -> length++;


      //if currentNode is full
      if (currentNode -> length == 5) {
        split(currentNode, location);
        //std::cout << "split" << std::endl;
      } // end if

      keepGoing = false;

      /*
      // print array for testing
      for (int x = 0; x < currentNode -> length; x++) {
        std::cout << currentNode -> keys[x] << ", ";
        //std::cout << temp[x];
      }
      std::cout << std::endl;
      */

    // if currentNode is not a leaf
    } else {
      /*
      // find which child is going to have new key
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] < key) {
          location = i + 1;
        } // end if
      } // end for
      */

      currentNode = currentNode -> children[location + 1];
    } // end if
  } // end while
} // end insert

void BTree::split(Node* currentNode, int location) {
  // if currentNode has a parent
  if (currentNode -> parent != NULL) {
    std::cout << "has a parent" << std::endl;

  // if currentNode doesn't have a parent
  } else {
    // create a new parent node
    Node* parent = new Node();
    root = parent;

    parent -> keys[0] = currentNode -> keys[2];
    parent -> length++;

    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;
    parent -> children[0] = left;

    Node* right = new Node(currentNode -> keys[3], true, parent);
    right -> keys[1] = currentNode -> keys[4];
    right -> length = 2;
    parent -> children[1] = right;
  }
}











// space
