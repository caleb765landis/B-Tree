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

  while (keepGoing) {
    // if currentNode is a leaf
    if (currentNode -> leaf == true) {
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
      if (currentNode -> length >= 5) {
        split(currentNode, location);
        //std::cout << "split" << std::endl;
      } // end if

      keepGoing = false;


    // if currentNode is not a leaf
    } else {
      //int location = currentNode -> length - 1;
      int location = 0;

      // find which child is going to have new key
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] < key) {
          location = i + 1;
        } // end if
      } // end for


      currentNode = currentNode -> children[location];
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

    // shift elements forward
    for (int j = parent -> length; j > parentLocation; j--) {
       parent -> keys[j] = parent -> keys[j - 1];
       //parent -> children[j+1] = parent -> children[j];
    }

    // insert median into correct position in parent's keys
    parent -> keys[parentLocation] = median;
    parent -> length++;
    parent -> hasChildren = true;

    /*
    // if parent is full
    if (parent -> length == 5) {
      split(parent, parentLocation);
    } // end if
    */


    // split currentNode
    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;

    Node* right = new Node(currentNode -> keys[3], true, parent);
    right -> keys[1] = currentNode -> keys[4];
    right -> length = 2;


    // if currentNode has children, update split nodes' children
    if (currentNode -> leaf == false) {
      left -> leaf = false;
      right -> leaf = false;

      for (int i = 0; i <= 2; i++) {
        left -> children[i] = currentNode -> children[i];
        right -> children[i] = currentNode -> children[i + 4];
      } // end for
    }


    // update parent's children positions
    for (int k = parent -> length + 1; k > parentLocation; k--) {
      parent -> children[k] = parent -> children[k-1];
    }

    parent -> children[parentLocation] = left;
    parent -> children[parentLocation + 1] = right;


    // if parent is full
    if (parent -> length == 5) {
      //std::cout << "full" << parent -> children[5] -> keys[0] << std::endl;
      split(parent, parentLocation);
    } // end if

  // if currentNode doesn't have a parent
  } else {
    // create a new parent node
    Node* parent = new Node();
    root = parent;

    parent -> keys[0] = currentNode -> keys[2];
    parent -> length++;
    parent -> hasChildren = true;


    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;
    parent -> children[0] = left;

    Node* right = new Node(currentNode -> keys[3], true, parent);
    right -> keys[1] = currentNode -> keys[4];
    right -> length = 2;
    parent -> children[1] = right;


    // if currentNode has children, update split nodes' children
    if (currentNode -> leaf == false) {
      left -> leaf = false;
      right -> leaf = false;

      for (int i = 0; i <= 2; i++) {
        left -> children[i] = currentNode -> children[i];
        right -> children[i] = currentNode -> children[i + 3];
      } // end for
    }
  }
}


void BTree::print(Node* currentNode) {
  //std::cout << "[(" << currentNode -> length << ") ";
  for (int i = 0; i < currentNode -> length; i++) {
    if (currentNode -> leaf == false) {
       //cout << "next ";
       print(currentNode -> children[i]);
    } // end if
    std::cout << currentNode -> keys[i] << ", ";
  } // end for
  //std::cout << "] ";

  //cout << "last ";


  if (currentNode -> leaf == false) {
    print(currentNode -> children[currentNode -> length]);
  } // end if
} // end print

void BTree::search(Node* currentNode, int n) {
  for (int i = 0; i < currentNode -> length; i++) {
    if (currentNode -> leaf == false) {
      search(currentNode -> children[i], n);
    } // end if

    if (currentNode -> keys[i] == n) {
      std::cout << currentNode -> keys[i] << ", ";
    } // end if
  } // end for

  if (currentNode -> leaf == false) {
    search(currentNode -> children[currentNode -> length], n);
  } // end if
} // end search


/*
void BTree::depth(Node* currentNode, int newDepth) {
  if (currentNode -> leaf == false) {
    newDepth++;
    depth(currentNode -> children[0], newDepth);
  } else {
    std::cout << "depth: " << newDepth << std::endl;
  }
}
*/









// space
