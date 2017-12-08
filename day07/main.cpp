#include <unordered_map>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>


class Program {
  public:
    Program(const std::string &name, int weight) 
      :name(name), weight(weight) {}
    std::string name;
    int weight;
    std::vector<Program*> children;
    Program* parent; 
};
int main() {
  std::string line;
  Program* root;
  std::unordered_map<std::string, std::pair<int,std::vector<std::string> > > to_do;
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string name;
    iss >> name;
    char x;
    iss >> x;
    int weight;
    iss >> weight;
    iss >> x;
    iss >> x;
    iss >> x;
    std::vector<std::string> children;
    std::string child;
    while (std::getline(iss, child, ',')) {
      children.push_back(child);
    }
    //std::cout << name << " weight: " << weight << " Children: ";
    //for (unsigned int i = 0; i < children.size(); ++i) {
      //std::cout << children[i] << " ";
    //}
    //std::cout << std::endl;
    to_do.insert(std::make_pair(name, std::make_pair(weight, children)));
    if (!root) {
      root = new Program(name, weight);
    } else {
      for (unsigned int i = 0; i < children.size(); ++i) {
	if(root->name == children[i]) {
	  Program* tmp = root;
	  root = new Program(name, weight);
	  root->children.push_back(tmp);
      }
    }
  }
}
