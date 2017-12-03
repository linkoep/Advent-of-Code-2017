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
    int min = 9999999;
    int max = 0;
    for (unsigned int j = 0; j < input[i].size(); ++j) {
      if (input[i][j] > max) {
	max = input[i][j];
      }
      if (input[i][j] < min) {
	min = input[i][j];
      }
    }
    sum += max - min;
  }
  std::cout << sum << std::endl;
}
