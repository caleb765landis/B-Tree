// main.cpp
#include <iostream>
#include <stdlib.h> // rand(), srand()
#include <cstdlib> // std::isDigit(), system
#include <algorithm> // find()
#include <vector>
#include <sstream>
#include "BTree.h"
#include "Node.h"

// prototype
bool isNumber(std::string string);

int main() {
  // clear screen to start the program
  system("clear");

  bool keepGoing = true;
  int input;

  while (keepGoing) {
    // get input from user
    std::cout << "Please specify the number of elements (N) such that N >= 400: ";
    std::cin.clear();
    std::string tempstring;
    std::cin >> tempstring;
    std::cout << std::endl;

    // check if user input is a number
    // if all characters in string are a number, convert string to int, set k = int
    if (isNumber(tempstring)) {
      std::stringstream ss;
      ss << tempstring;
      ss >> input;

      // check if input >= 400 is true
      if (input < 400) {
        std::cout << "N must be greater than or equal to 400." << std::endl << std::endl;

      // input >= 400, set n, end loop
      } else {
        keepGoing = false;
      } // end if k is in acceptable range

    // if user input isn't a number, restart loop
    } else {
      std::cout << "N must be an integer." << std::endl << std::endl;
      std::cin.clear();
      std::cin.ignore();
    } // end if user input is a number
  } // end while

  int n = input;

  // create a vector of keys
  std::vector<int> k;

  int i = 0;
  while (i < n) {
    bool duplicate = false;

    // get a random number
    int num = rand() % ((3*n) + 1);

    // check to make sure random num is not already in vector
    if (std::find(k.begin(), k.end(), num) != k.end()) {
      duplicate = true;
    } // end if

    if (duplicate == false) {
      k.push_back(num);
      i++;
    } // end if
  } // end while

  // create B-Tree and set root
  BTree t = BTree(k[0]);

  // insert keys from vector into B-Tree
  for (int j = 1; j < n; j++) {
	   t.insert(k[j]);
  } // end for

  // print all elements in B-Tree
  std::cout << "All elements in B-Tree: " << std::endl;
  t.print(t.root);
  std::cout << std::endl << std::endl;

  // print all elements in range [n, 2n]
  std::cout << "All elements in B-Tree within range [" << n << ", " << (2 * n) << "]: " << std::endl;
  for (int i = n; i <= (2*n); i++) {
    t.search(t.root, i);
  } // end search for
  std::cout << std::endl << std::endl;
} // end main

// checks if all characters in given string are numbers
// returns true if all characters are numbers
bool isNumber(std::string string) {
  // go through each character in string
  for (int i = 0; i < string.length(); i++) {
    // if current character in string is not a digit return false
    if (std::isdigit(string.at(i)) == 0) {
      return false;
    } // end if
  } // end for
  return true;
} // end isNumber()
