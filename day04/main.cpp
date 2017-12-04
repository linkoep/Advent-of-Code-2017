#include <unordered_set>
#include <string>
#include <iostream>
#include <sstream>

int main() {
  std::cout << "Enter input: ";
  //Number of valid passphrases
  int count = 0;
  std::string line;
  while(std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::unordered_set<std::string> input;
    std::string in;
    bool hasDups = false;
    while (iss >> in && !hasDups) {
      //std::cout << in << " ";
      if(!input.insert(in).second) {
	hasDups = true;
      }
    }
    if (!hasDups) {
      ++count;
    }
    //std::cout << count << std::endl;
  }
  std::cout << "There are: " << count << " valid passphrases" << std::endl;
  return 0;
}
