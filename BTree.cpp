// BTree.cpp

#include "Node.h"
#include "BTree.h"
#include <iostream>
using namespace std;

BTree::BTree(int key) {
  root = new Node(key, true, NULL);
  //root = Node(key, true, NULL);
}

BTree::~BTree() {
  delete root;
} // end destructor

void BTree::insert(int key) {
  bool keepGoing = true;
  Node* currentNode = root;
  //Node currentNode = root;
  //int location = currentNode -> length - 1;

  while (keepGoing) {
    // if currentNode is a leaf
    if (currentNode -> leaf == true) {
    //if (currentNode.leaf == true) {
      int location = 0;


      // find location where key will be placed
      for (int i = 0; i < currentNode -> length; i++) {
      //for (int i = 0; i < currentNode.length; i++) {
        // if currentNode's current key is less than key, increase location
		if (currentNode -> keys[i] < key) {
        //if (currentNode.keys[i] < key) {
          location = i + 1;
        }  // end if
      } // end for


      // shift elements forward
      // starting at the last element's index + 1, dec j until key's location
      for (int j = currentNode -> length; j >= location; j--) {
      //for (int j = currentNode.length; j >= location; j--) {
        // increase current key's index
        currentNode -> keys[j] = currentNode -> keys[j - 1];
        //currentNode.keys[j] = currentNode.keys[j - 1];
      } // end for

      // insert key into correct position in keys
      currentNode -> keys[location] = key;
      currentNode -> length++;
      //currentNode.keys[location] = key;
      //currentNode.length++;

      //if currentNode is full
      if (currentNode -> length >= 5) {
      //if (currentNode.length >= 5) {
        split(currentNode, location);
      } // end if

      keepGoing = false;


    // if currentNode is not a leaf
    } else {
      //int location = currentNode -> length - 1;
      int location = 0;

      // find which child is going to have new key
      for (int i = 0; i < currentNode -> length; i++) {
      //for (int i = 0; i < currentNode.length; i++) {
        if (currentNode -> keys[i] < key) {
        //if (currentNode.keys[i] < key) {
          location = i + 1;
        } // end if
      } // end for


      currentNode = currentNode -> children[location];
      //currentNode = currentNode.children[location];
    } // end if
  } // end while
} // end insert

// assuming currentNode's length is 5
void BTree::split(Node* currentNode, int location) {
  // if currentNode has a parent
  if (currentNode -> parent != NULL) {
  //if (currentNode.parent != NULL) {
    // specify parent
    Node* parent = currentNode -> parent;
    //Node* parent = currentNode.parent;
    int parentLocation = 0;
    int median = currentNode -> keys[2];
    //int median = currentNode.keys[2];

    // find location where median will be placed
    for (int i = 0; i < parent -> length; i++) {
      // if parent's current key is less than median, increase location
      if (parent -> keys[i] < median) {
        parentLocation = i + 1;
      }  // end if
    } // end for

    // shift elements forward
    // starting at the last element's index + 1, dec j until median's location
    for (int j = parent -> length; j > parentLocation; j--) {
      // increase current key's index
      parent -> keys[j] = parent -> keys[j - 1];
    } // end for

    // insert median into correct position in parent's keys
    parent -> keys[parentLocation] = median;
    parent -> length++;

    // split currentNode
    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;
    Node* right = new Node(currentNode -> keys[3], true, parent);
    right -> keys[1] = currentNode -> keys[4];
    right -> length = 2;
    /*
    Node left = Node(currentNode -> keys[0], true, parent);
    left.keys[1] = currentNode -> keys[1];
    left.length = 2;
    Node right = Node(currentNode -> keys[3], true, parent);
    right.keys[1] = currentNode -> keys[4];
    right.length = 2;
    */


    // if currentNode has children, update split nodes' children
    if (currentNode -> leaf == false) {
      left -> leaf = false;
      right -> leaf = false;

      for (int i = 0; i <= 2; i++) {
        left -> children[i] = currentNode -> children[i];
		left -> children[i] -> parent = left;
		right -> children[i] = currentNode -> children[i + 3];
		right -> children[i] -> parent = right;
      } // end for
    } // end if
	
	//std::cout << "parent: " << parent -> keys[0] << std::endl;

	/*
    if (currentNode -> leaf == false) {
      left.leaf = false;
      right.leaf = false;

      for (int i = 0; i <= 2; i++) {
        left.children[i] = currentNode -> children[i];
        right.children[i] = currentNode -> children[i + 4];
      } // end for
    } // end if
    */

    // update parent's children positions
    // shift elements forward
    for (int k = parent -> length + 1; k > parentLocation; k--) {
      // increase parent's child key's index
      //std::cout << "parent: " << parent -> keys[0] << std::endl;
	  //std::cout << "parent2: " << parent -> keys[1] << std::endl;
	  parent -> children[k] = parent -> children[k-1];
	  //std::cout << "parent3: " << parent -> children[parentLocation] -> keys[0] << std::endl;
	} // end for

	
	//std::cout << "parent: " << parent -> keys[0] << std::endl;

    // set left and right split children to correct spot in parent's children[]
    // left's posiiton should be originally empty
    parent -> children[parentLocation] = left;
    // right's position should be originally currentNode (unsplit, full)
    parent -> children[parentLocation + 1] = right;


    // if parent is full
    if (parent -> length == 5) {
      split(parent, parentLocation);
    } // end if

    //delete currentNode;

  // if currentNode doesn't have a parent
  // currentNode is root
  } else {
    // create a new parent node
    Node* parent = new Node();
    //Node parent = Node();
	root = parent;
	
    /*
    // set parent's first key to median
    parent.keys[0] = currentNode -> keys[2];
    parent.length++;

    // set left side of split currentNode
    Node left = Node(currentNode -> keys[0], true, &parent);
    left.keys[1] = currentNode -> keys[1];
    left.length = 2;
    parent.children[0] = left;

    // set right side of split currentNode
    Node right = Node(currentNode -> keys[3], true, &parent);
    right.keys[1] = currentNode -> keys[4];
    right.length = 2;
    parent.children[1] = right;


    // if currentNode has children, update split nodes' children
    if (currentNode -> leaf == false) {
      // since they have children, left and right are not leaves
      left.leaf = false;
      right.leaf = false;

      // set first 3 children
      for (int i = 0; i <= 2; i++) {
        // left is currentNode's [0-2]
        left.children[i] = currentNode -> children[i];
        // right is currentNode's [3-6]
        right.children[i] = currentNode -> children[i + 3];
      } // end for
    } // end if currentNode has children

    */
    // set parent's first key to median
    parent -> keys[0] = currentNode -> keys[2];
    parent -> length++;

    // set left side of split currentNode
    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;
    parent -> children[0] = left;
    //std::cout << "current: " << currentNode -> keys[0] << " " << currentNode -> keys[1] << currentNode -> keys[2] << currentNode -> keys[3] << std::endl;
	//std::cout << "Split: " << left -> keys[0] << " " << left -> keys[1] << std::endl;
	// set right side of split currentNode
    Node* right = new Node(currentNode -> keys[3], true, parent);
    right -> keys[1] = currentNode -> keys[4];
    right -> length = 2;
    parent -> children[1] = right;


    // if currentNode has children, update split nodes' children
    if (currentNode -> leaf == false) {
      // since they have children, left and right are not leaves
      left -> leaf = false;
      right -> leaf = false;

      // set first 3 children
      for (int i = 0; i <= 2; i++) {
        // left is currentNode's [0-2]
        left -> children[i] = currentNode -> children[i];
		left -> children[i] -> parent = left;
        // right is currentNode's [3-5]
        right -> children[i] = currentNode -> children[i + 3];
		right -> children[i] -> parent = right;
      } // end for
    } // end if currentNode has children
    //delete currentNode;
  } // end if currentNode has parent
} // end split


void BTree::print(Node* currentNode) {
  /*
  //std::cout << "[(" << currentNode -> length << ") ";
  for (int i = 0; i < currentNode.length; i++) {
    if (currentNode.leaf == false) {
       //cout << "next ";
       print(currentNode.children[i]);
    } // end if
    std::cout << currentNode.keys[i] << ", ";
  } // end for
  //std::cout << "] ";

  //cout << "last ";


  if (currentNode.leaf == false) {
    print(currentNode.children[currentNode.length]);
  } // end if
  */
  //std::cout << "[(Length: " << currentNode -> length << ") ";
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
  /*
  for (int i = 0; i < currentNode.length; i++) {
    if (currentNode.leaf == false) {
      search(currentNode.children[i], n);
    } // end if

    if (currentNode.keys[i] == n) {
      std::cout << currentNode.keys[i] << ", ";
    } // end if
  } // end for

  if (currentNode.leaf == false) {
    search(currentNode.children[currentNode.length], n);
  } // end if
  */
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
