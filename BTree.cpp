// BTree.cpp

#include "Node.h"
#include "BTree.h"

BTree::BTree(int key) {
  root = new Node(key, true, NULL);
} // end constructor

BTree::~BTree() {
  delete root;
} // end destructor

// search for node to insert key into
// insert into proper position
void BTree::insert(int key) {
  bool keepGoing = true;
  Node* currentNode = root;

  // keepGoing until location to insert key is found
  while (keepGoing) {
    // if currentNode is a leaf
    if (currentNode -> leaf == true) {
      int location = 0;

      // find location where key will be placed
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] < key) {
          location = i + 1;
        } // end if
      } // end for

      // shift elements forward
      // starting at the last element's index + 1, dec j until key's location
      for (int j = currentNode -> length; j >= location; j--) {
        currentNode -> keys[j] = currentNode -> keys[j - 1];
      } // end for

      // insert key into correct position in keys
      currentNode -> keys[location] = key;
      currentNode -> length++;

      //if currentNode is full
      if (currentNode -> length >= 5) {
        split(currentNode);
      } // end if

      keepGoing = false;

    // if currentNode is not a leaf
    } else {
      int location = 0;

      // find which child is going to have new key
      for (int i = 0; i < currentNode -> length; i++) {
        if (currentNode -> keys[i] < key) {
          location = i + 1;
        } // end if
      } // end for

      // set next currentNode to to search through
      currentNode = currentNode -> children[location];
    } // end if
  } // end while
} // end insert

// assuming currentNode's length is 5, split currentNode
void BTree::split(Node* currentNode) {
  // if currentNode has a parent
  if (currentNode -> parent != NULL) {
    // specify parent
    Node* parent = currentNode -> parent;
    int parentLocation = 0;
    int median = currentNode -> keys[2];

    // find location where median will be placed
    for (int i = 0; i < parent -> length; i++) {
      // if parent's current key is less than median, increase location
      if (parent -> keys[i] < median) {
        parentLocation = i + 1;
      } // end if
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
    // set left side of split currentNode
    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;
    // set right side of split currentNode
    Node* right = new Node(currentNode -> keys[3], true, parent);
    right -> keys[1] = currentNode -> keys[4];
    right -> length = 2;

    // if currentNode has children, update split nodes' children
    if (currentNode -> leaf == false) {
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
    } // end if

    // update parent's children positions
    // shift elements forward
    for (int k = parent -> length + 1; k > parentLocation; k--) {
      // increase parent's child key's index
      parent -> children[k] = parent -> children[k-1];
    } // end for

    // set left and right split children to correct spot in parent's children[]
    // left's posiiton should originially be empty
    parent -> children[parentLocation] = left;
    // right's position should originally be currentNode (unsplit, full)
    parent -> children[parentLocation + 1] = right;

    // if parent is full, split parent
    if (parent -> length == 5) {
      split(parent);
    } // end if

  // if currentNode doesn't have a parent
  // currentNode is root
  } else {
    // create a new parent node
    Node* parent = new Node();
    root = parent;

    // set parent's first key to median
    parent -> keys[0] = currentNode -> keys[2];
    parent -> length++;

    // split currentNode
    // set left side of split currentNode
    Node* left = new Node(currentNode -> keys[0], true, parent);
    left -> keys[1] = currentNode -> keys[1];
    left -> length = 2;
    parent -> children[0] = left;
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
  } // end if currentNode has parent
} // end split

// prints every element in B-Tree through recursive in-order traversal
void BTree::print(Node* currentNode) {
  for (int i = 0; i < currentNode -> length; i++) {
    if (currentNode -> leaf == false) {
       print(currentNode -> children[i]);
    } // end if
    std::cout << currentNode -> keys[i] << ", ";
  } // end for

  if (currentNode -> leaf == false) {
    print(currentNode -> children[currentNode -> length]);
  } // end if
} // end print

// searches recursively through in-order traversal for int n
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
