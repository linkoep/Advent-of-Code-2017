#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>

void connect(const std::unordered_map<int, std::vector<int> > &contacts, std::set<int> &connected, int i) {
  std::vector<int> direct_connections = contacts.find(i)->second;
  for (unsigned int j = 0; j < direct_connections.size(); ++j) {
    bool success = connected.insert(direct_connections[j]).second;
    if (success) {
      connect(contacts, connected, direct_connections[j]);
    }
  }
}

int main() {
  std::unordered_map<int, std::vector<int> > contacts;
  std::string line;
  while (std::getline(std::cin, line)) {
    std::stringstream ss(line);
    int prog;
    std::string pipe;
    ss >> prog >> pipe;
    std::vector<int> friends;
    std::string friendString;
    while (std::getline(ss, friendString, ',')) {
      friends.push_back(std::stoi(friendString));
    }
    contacts.insert(std::make_pair(prog, friends));
  }
  //Print for debugging
  for (std::unordered_map<int, std::vector<int> >::iterator itr = contacts.begin(); itr != contacts.end(); ++itr) {
    std::cout << itr->first << " talks to ";
    for (unsigned int i = 0; i < itr->second.size(); ++i) {
      std::cout << itr->second[i] << " ";
    }
    std::cout << std::endl;
  }

  std::set<int> connected;
  connected.insert(0);
  connect(contacts, connected, 0);
  for (std::set<int>::iterator itr = connected.begin(); itr != connected.end(); ++itr) {
    std::cout << *itr << " ";
  }
  std::cout << std::endl << connected.size() << std::endl;
}
