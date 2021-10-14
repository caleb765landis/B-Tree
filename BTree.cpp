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
    /*
    std::cout << "keys[0] " <<  currentNode -> keys[0] << std::endl;
    std::cout << "keys[1] " <<  currentNode -> keys[1] << std::endl;
    std::cout << "keys[2] " <<  currentNode -> keys[2] << std::endl;
    */
    
    // if currentNode is a leaf
    if (currentNode -> leaf == true) {
      // find location where key will be placed
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] > key) {
          location = i;
        }  // end if
      } // end for
      //std::cout << location << std::endl;

      for (int j = currentNode -> length; j > location; j--) {
         currentNode -> keys[j] = currentNode -> keys[j - 1];
      }

      currentNode -> keys[location] = key;
      currentNode -> length++;

      /*
      // create a temp array
      int* temp = new int[5];

      // fill temp with ints from keys up until location
      if (location != 0) {
      for (int j = 0; j < location; j++) {
        temp[j] = currentNode -> keys[j];
      } // end for
      }

      // add key
      temp[location] = key;

      // fill temp with remaining ints from keys, if any
      for (int k = location; k < 5; k++) {
        temp[k+1] = currentNode -> keys[k];
      } // end for

      // set keys = temp
      currentNode -> keys = temp;
      */




      //if currentNode is full
      if (currentNode -> length == 5) {
        // split(currentNode)
        std::cout << "leaf is full" << std::endl;
      } // end if

      keepGoing = false;


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
