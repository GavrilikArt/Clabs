#include <iostream>
#include "Tree.h"

int main() {
  Tree tree;
  std::string str;
  std::cout << "Enter a string you wanna operate with:\n";
  std::cin >> str;
  for (auto i : str) {
    tree.insert(i);
  }
  std::cout << "Enter a char you wanna operate with:\n";
  char ch;
  std::cin >> ch;
  std::cout << "There are " <<tree.count(ch) << " under this node";
  return 0;
}
