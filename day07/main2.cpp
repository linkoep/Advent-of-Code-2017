#include <unordered_set>
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>

int main() {
  std::unordered_set<std::string> children;
  std::unordered_set<std::string> parents;
  std::string line;
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string name;
    iss >> name;
    parents.insert(name);
    char x;
    iss >> x;
    int weight;
    iss >> weight;
    iss >> x;
    iss >> x;
    iss >> x;
    std::string child;
    //std::cout << name << " weight: " << weight << " Children: ";
    while (std::getline(iss, child, ',')) {
      child = child.substr(1);
      assert((children.insert(child)).second);
      //std::cout << child << " ";
    }
    //std::cout << std::endl;
  }
  for (std::unordered_set<std::string>::iterator itr = parents.begin(); itr != parents.end(); ++itr) {
    if (children.find(*itr) == children.end()) {
      std::cout << *itr << std::endl;
    }
  }
}
