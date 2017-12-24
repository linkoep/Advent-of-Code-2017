#include <iostream>
#include <cassert>
#include <sstream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
  std::unordered_map<char, long> registers;
  std::vector<std::string> instructions;
  std::string instruction;
  long last;
  while (std::getline(std::cin, instruction)) {
    instructions.push_back(instruction);
  }
  for (int i = 0; i >= 0 && i < instructions.size(); ++i) {
    std::istringstream iss(instructions[i]);
    iss >> instruction;
    char reg;
    iss >> reg;
    if (instruction == "snd") {
      last = registers[reg];
    } else if (instruction == "set") {
      std::string in;
      int value;
      iss >> in;
      try {
	value = std::stoi(in);
      } catch (...) {
	value = registers[in[0]];
      }
      registers[reg] = value;
    } else if (instruction == "add") {
      std::string in;
      int value;
      iss >> in;
      try {
	value = std::stoi(in);
      } catch (...) {
	value = registers[in[0]];
      }
      registers[reg] += value;
    } else if (instruction == "mul") {
      std::string in;
      int value;
      iss >> in;
      try {
	value = std::stoi(in);
      } catch (...) {
	value = registers[in[0]];
      }
      registers[reg] *= value;
    } else if (instruction == "mod") {
      std::string in;
      int value;
      iss >> in;
      try {
	value = std::stoi(in);
      } catch (...) {
	value = registers[in[0]];
      }
      assert(value != 0);
      registers[reg] %= value;
    } else if (instruction == "rcv") {
      if (registers[reg] != 0) {
	std::cout << last << std::endl;
	exit(0);
      }
    } else if (instruction == "jgz") {
      std::string in;
      int value;
      iss >> in;
      try {
	value = std::stoi(in);
      } catch (...) {
	value = registers[in[0]];
      }
      if (registers[reg] > 0) {
	i--;
	i+= value;
      }
    }
    std::cout << instruction << " " << reg << " " << registers[reg] << std::endl;
  }
}
