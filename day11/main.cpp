#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> instructions;
  std::string instruction;
  while(std::getline(std::cin, instruction, ',')){
    instructions.push_back(instruction);
  }

  int x = 0;
  int y = 0;
  int z = 0;

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

  }
  std::cout << std::abs(x) + std::abs(y) + std::abs(z) << std::endl;
}
