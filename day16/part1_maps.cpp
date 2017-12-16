#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
  std::map<char, int> locations;
  std::map<int, char> programs;
  for (unsigned int i = 0; i < 16; ++i) {
    locations.insert(std::make_pair('a'+i, i));
    programs.insert(std::make_pair(i, 'a'+i));
  }
  std::vector<std::string> instructions;
  std::string in;
  while(std::getline(std::cin, in, ',')) {
    instructions.push_back(in);
  }
  for (unsigned int i = 0; i < instructions.size(); ++i) {

    if(instructions[i][0] == 's') {
      int spin = std::stoi(instructions[i].substr(1));
      for (std::map<char, int>::iterator itr = locations.begin(); itr != locations.end(); ++itr) {
	itr->second += spin;
	itr->second %= 16;
	programs[itr->second] = itr->first;
      }
    } else if (instructions[i][0] == 'x') {
      int slash = instructions[i].find('/');
      int location1 = std::stoi(instructions[i].substr(1, slash));
      int location2 = std::stoi(instructions[i].substr(slash+1));
      std::swap(programs[location1], programs[location2]);
      locations[programs[location1]] = location1;
      locations[programs[location2]] = location2;
    } else if (instructions[i][0] == 'p') {
      char a = instructions[i][1];
      char b = instructions[i][3];
      std::swap(locations[a], locations[b]);
      programs[locations[a]] = a;
      programs[locations[b]] = b;
    }
  }
  for (std::map<int, char>::iterator itr = programs.begin(); itr != programs.end(); ++itr) {
    std::cout << itr->second;
  }
  std::cout << std::endl;
}
