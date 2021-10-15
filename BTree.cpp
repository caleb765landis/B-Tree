// BTree.cpp

#include "Node.h"
#include "BTree.h"
#include <iostream>

BTree::BTree(int key) {
  root = new Node(key, true);
}

void BTree::insert(int key) {
  bool keepGoing = true;
  Node* currentNode = root;
  int location = 0;

  while (keepGoing) {
    // if currentNode is a leaf
    if (currentNode -> leaf == true) {
      // find location where key will be placed
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] < key) {
          location = i + 1;
        }  // end if
      } // end for

      // shift elements forward
      for (int j = currentNode -> length; j >= location; j--) {
         currentNode -> keys[j] = currentNode -> keys[j - 1];
      }

      // insert key into correct position in keys
      currentNode -> keys[location] = key;
      currentNode -> length++;


      //if currentNode is full
      if (currentNode -> length == 5) {
        // split(currentNode)
        std::cout << "leaf is full" << std::endl;
      } // end if

      keepGoing = false;

      // print array for testing
      for (int x = 0; x < currentNode -> length; x++) {
        std::cout << currentNode -> keys[x] << ", ";
        //std::cout << temp[x];
      }
      std::cout << std::endl;

    // if currentNode is not a leaf
    } else {
      // find which child is going to have new key


      //currentNode = node pointer for next child to search through
    } // end if
  } // end while
} // end insert
