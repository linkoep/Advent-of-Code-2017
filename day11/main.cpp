#include <sstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> instructions;
  std::string line;
  while(std::getline(std::cin, line)){
    std::istringstream ss(line);
    std::string instruction;
    while(std::getline(ss, instruction, ',')) {
      instructions.push_back(instruction);
    }
  }

  int x = 0;
  int y = 0;
  int z = 0;

  int max_distance = 0;

  for(unsigned int i = 0; i < instructions.size(); ++i) {
    if(instructions[i] == "n") {
      ++y; --z;
    } else if (instructions[i] == "ne" ) {
      ++x; --z;
    } else if (instructions[i] == "se" ) {
      ++x; --y;
    } else if (instructions[i] == "s" ) {
      --y; ++z;
    } else if (instructions[i] == "sw" ) {
      --x; ++z;
    } else if (instructions[i] == "nw" ) {
      --x; ++y;
    }

max_distance = std::max(std::abs(x) + std::abs(y) + std::abs(z), max_distance);

  }
  std::cout << (std::abs(x) + std::abs(y) + std::abs(z) )/2<< std::endl;
  std::cout << max_distance/2 << std::endl;
}
