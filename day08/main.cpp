#include <unordered_map>
#include <sstream>
#include <iostream>
#include <string>
#include <cassert>

int main() {
  std::unordered_map<std::string, int> registers;
  std::string line;
  int max_ever = -10000;
  while (std::getline(std::cin, line)) {
    std::istringstream ss(line);
    std::string reg_name;
    std::string operation;
    int amt;
    std::string x;
    std::string comp_reg_name;
    std::string condition;
    int val;
    ss >> reg_name >> operation >> amt >> x >> comp_reg_name >> condition >> val;
    assert(x == "if");
    bool valid = false;
    if (condition == ">") {
      if (registers[comp_reg_name] > val) {valid = true;}
    } else if (condition == "<") {
      if (registers[comp_reg_name] < val) {valid = true;}
    } else if (condition == ">=") {
      if (registers[comp_reg_name] >= val) {valid = true;}
    } else if (condition == "<=") {
      if (registers[comp_reg_name]  <= val) {valid = true;}
    } else if (condition == "==") {
      if (registers[comp_reg_name]  == val) {valid = true;}
    } else if (condition == "!=") {
      if (registers[comp_reg_name]  != val) {valid = true;}
    } else {
      std::cerr << "Invalid Condtion" << std::endl;
    }
    if(valid) {
      if (operation == "inc") {
	registers[reg_name] += amt;
      } else if (operation == "dec") {
	registers[reg_name] -= amt;
      }
      if (registers[reg_name] > max_ever) {
	max_ever = registers[reg_name];
      }
    }
  }
  int max = -10000;
  for (std::unordered_map<std::string, int>::iterator itr = registers.begin();
      itr != registers.end(); ++itr) {
    //std::cout << itr->second << std::endl;
    if (itr->second > max) {
      max = itr->second;
    }
  }
  std::cout << max << std::endl;
  std::cout << max_ever << std::endl;
}
