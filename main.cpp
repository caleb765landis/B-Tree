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

using namespace std;

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
      if (input < 18) {
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
  std::vector<int> k;


  cout << "Random ints: ";

  int i = 0;
  //srand(n);
  while (i < n) {
    bool duplicate = false;

    int num = rand() % ((3*n) + 1);
    std::cout << num << ", ";

    if (std::find(std::begin(k), std::end(k), num) != std::end(k)) {
      duplicate = true;
    }

    if (duplicate == false) {
      //k[i] = num;
      //k.insert(i, num);
      k.push_back(num);
      i++;
    } // end if
  } // end for/while
    std::cout << std::endl;


    /*
    for (int j = 0; j < n; j++) {
      if (num == k[j]) {
        duplicate = true;
      } // end if
    } // end for

    if (duplicate == false) {
      k[i] = num;
    }
    */

  BTree t = BTree(k[0]);

  std::cout << "last " << k[n - 1] << std::endl;


  cout << "Elements in k[n]: " << endl;
  std::cout << k[0] << ", " << endl;
  for (int j = 1; j < n; j++) {
    std::cout << k[j] << ", " << endl;
    t.insert(k[j]);
  }
  std::cout << std::endl;


  /*
  for (int x = 0; x < t.root -> length; x++) {
    std::cout << "root " << t.root -> keys[x] << ", ";
    //std::cout << temp[x];
  }
  std::cout << std::endl;

  for (int x = 0; x < t.root -> children[0] -> length; x++) {
    std::cout << "left " << t.root -> children[0] -> keys[x] << ", ";
    //std::cout << temp[x];
  }
  std::cout << std::endl;
  std::cout << std::endl;


  for (int x = 0; x < t.root -> children[0] -> children[0] -> length; x++) {
    std::cout << t.root -> children[0] -> children[0] -> keys[x] << ", ";
    //std::cout << temp[x];
  }
  std::cout << std::endl;
  */

  //std::cout << t.root -> children[0] -> children[0] -> keys[0] << std::endl;

  /*
  if (t.root -> children[0] -> leaf == true) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }


  if (t.root -> children[1] -> children[2] -> leaf == true) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  */

  //t.depth(t.root, 0);
  std::cout << "All elements in B-Tree: " << std::endl;
  t.print(t.root);
  std::cout << std::endl << std::endl;

  std::cout << "All elements in B-Tree within range [" << n << ", " << (2 * n) << "]: " << std::endl;
  for (int i = n; i <= (2*n); i++) {
    t.search(t.root, i);
  } // end search for
  std::cout << std::endl;
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








// space
