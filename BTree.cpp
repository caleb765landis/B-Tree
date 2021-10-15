// BTree.cpp

#include "Node.h"
#include "BTree.h"
#include <iostream>
using namespace std;

BTree::BTree(int key) {
  root = new Node(key, true, NULL);
}

void BTree::insert(int key) {
  bool keepGoing = true;
  Node* currentNode = root;
  //int location = currentNode -> length - 1;

  /*
  // find location of where key will be placed or
  // which child is going to have new key
  for (int i = 0; i < currentNode -> length; i++) {
    if (currentNode -> keys[i] < key) {
      location = i + 1;
    } // end if
  } // end for
  */

  while (keepGoing) {
    // if currentNode is a leaf
    if (currentNode -> leaf == true) {
      /*
      int location;
      for (int i = currentNode -> length; currentNode -> keys[i] > key; i--) {
        currentNode -> keys[i + 1] = currentNode -> keys[i];
        location = i;
      }
      currentNode -> keys[location + 1] = key;
      currentNode -> length++;
      */


      //int location = currentNode -> length - 1;
      int location = 0;


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
        split(currentNode, location);
        //std::cout << "split" << std::endl;
      } // end if

      keepGoing = false;


    // if currentNode is not a leaf
    } else {
      //int location = currentNode -> length - 1;
      int location = 0;
      /*
      int location;
      for (int i = currentNode -> length - 1; currentNode -> keys[i] > key; i--) {
        currentNode -> keys[i + 1] = currentNode -> keys[i];
        location = i;
      }
      */

      // find which child is going to have new key
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] < key) {
          location = i + 1;
        } // end if
      } // end for

      //if (key > currentNode -> keys[0]) {
        //currentNode = currentNode -> children[location + 1];
        currentNode = currentNode -> children[location];
      //} else {
        //currentNode = currentNode -> children[0];
      //}

    } // end if
  } // end while
} // end insert

void BTree::split(Node* currentNode, int location) {
  // if currentNode has a parent
  if (currentNode -> parent != NULL) {
    Node* parent = currentNode -> parent;
    int parentLocation = 0;
    int median = currentNode -> keys[2];

    // find location where median will be placed
    for (int i = 0; i < parent -> length; i++) {
      if (parent -> keys[i] < median) {
        parentLocation = i + 1;
      }  // end if
    } // end for

    //parent -> length++;

    // shift elements forward
    for (int j = parent -> length; j > parentLocation; j--) {
       parent -> keys[j] = parent -> keys[j - 1];
       //parent -> children[j+1] = parent -> children[j];
    }

    // insert median into correct position in parent's keys
    parent -> keys[parentLocation] = median;
    parent -> length++;


    // if parent is full
    if (parent -> length == 5) {
      split(parent, parentLocation);
    } // end if


    // split currentNode
    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;

    Node* right = new Node(currentNode -> keys[3], true, parent);
    right -> keys[1] = currentNode -> keys[4];
    right -> length = 2;


    // update parent's children positions
    for (int k = parent -> length + 1; k > parentLocation; k--) {
      parent -> children[k] = parent -> children[k-1];
    }

    parent -> children[parentLocation] = left;
    parent -> children[parentLocation + 1] = right;



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
