//TO ANYONE READING THIS CODE
//IT IS A BADLY COBBLED-TOGETHER MESS 
//DO NOT PROCEED
//I WOULD NEVER EVER USE THIS FOR ANYTHING
//(Other than solving this one problem this one time
//in a competition with 24 other challenges focused on completion)


#include <unordered_set>
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stack>

void add_children(const std::string &n, std::stack<std::string> &to_do,
  std::unordered_map<std::string, std::vector<std::string> > tree) {
  std::vector<std::string> children = tree[n];
  for(unsigned int i = 0; i < children.size(); ++i) {
    to_do.push(children[i]);
    add_children(children[i], to_do, tree);
  }
}

int main() {
  std::unordered_set<std::string> children;
  std::unordered_set<std::string> parents;
  std::unordered_map<std::string, int> weights;
  std::unordered_map<std::string, std::vector<std::string> > tree;
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
    weights.insert(std::make_pair(name, weight));
    iss >> x;
    iss >> x;
    iss >> x;
    std::string child;
    std::vector<std::string> childrens;
    //std::cout << name << " weight: " << weight << " Children: ";
    while (std::getline(iss, child, ',')) {
      child = child.substr(1);
      assert((children.insert(child)).second);
      childrens.push_back(child);
      //std::cout << child << " ";
    }
    tree.insert(std::make_pair(name, childrens));
    //std::cout << std::endl;
  }
  std::string root;
  for (std::unordered_set<std::string>::iterator itr = parents.begin(); itr != parents.end(); ++itr) {
    if (children.find(*itr) == children.end()) {
      std::cout << *itr << std::endl;
      root = *itr;
      break;
    }
  }
  std::stack<std::string> to_do;
  to_do.push(root);
  add_children(root, to_do, tree);

  ////Print stack for debugging
  //std::stack<std::string> copy = to_do;
  //while(!copy.empty()) {
    //std::cout << copy.top() << std::endl;
    //copy.pop();
  //}

  while(!to_do.empty()) {
    int weight = 0;
    int balance = 0;
    std::vector<std::string> children = tree[to_do.top()];
    if(children.empty()) {
      std::cout << "Branch " << to_do.top() << " has weight " << weights[to_do.top()] << std::endl;
      to_do.pop();
      continue;
    }
    for (unsigned int i = 0; i < children.size(); ++i) {
      weight += weights[children[i]];
      balance = weights[children[i]];
    }
    if (balance != 0 && weight%balance != 0) {
      std::cout << weight << " " << balance << std::endl;
      for(unsigned int i = 0; i < children.size(); ++i) {
	std::cout << weights[children[i]] << " " << std::endl;
	std::vector<std::string> grandchildren = tree[children[i]];
	for (unsigned int j = 0; j < grandchildren.size(); ++j) {
	  std::cout << weights[grandchildren[j]] << std::endl;
	}
	std::cout << children[i] << std::endl;
      }
	std::cout << to_do.top() << std::endl;
      break;
    }
    weights[to_do.top()] +=weight;
    to_do.pop();
  }
}
