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

  std::vector<std::set<int> > connected(1);
  connected[0].insert(0);
  connect(contacts, connected[0], 0);
  for (std::unordered_map<int, std::vector<int> >::iterator itr = contacts.begin(); itr != contacts.end(); ++itr) {
    bool found = false;
    for(int i = 0; i < connected.size(); ++i) {
      if (connected[i].find(itr->first) != connected[i].end()) {
	found = true;
      }
    }
    if (!found) {
      connected.push_back(std::set<int>());
      connected.back().insert(itr->first);
      connect(contacts, connected.back(), itr->first);
    }
  }
  std::cout << std::endl << connected.size() << std::endl;
}
