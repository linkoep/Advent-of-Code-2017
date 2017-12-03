#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int main() {
  std::vector<std::vector<int> > input;
  std::string line;
  while(std::getline(std::cin, line)) {
    std::istringstream iss(line);
    int in;
    std::vector<int> input_row;
    while (iss >> in) {
      input_row.push_back(in);
    }
    input.push_back(input_row);
  }
  int sum = 0;
  for (unsigned int i = 0; i < input.size(); ++i) {
    for (unsigned int j = 0; j < input[i].size(); ++j) {
      for (unsigned int h = 0; h < input[i].size(); ++h) {
	if (input[i][j] == input[i][h]) {
	  continue;
	}
	if (input[i][j] % input[i][h] == 0) {
	  sum += input[i][j] / input[i][h]; 
	  break;
	}
      }
    }
  }
  std::cout << sum << std::endl;
}
