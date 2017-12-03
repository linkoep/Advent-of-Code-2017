#include <cassert>
#include <vector>
#include <iostream>
int main(int argc, char* argv[]) {
  std::vector<int> input;
  std::cout << "Please enter input" << std::endl;
  std::string in;
  std::cin >> in;
    for (unsigned int i = 0; i < in.length(); ++i) {
      input.push_back(in[i] - '0');
    }
  int sum = 0;
  for (unsigned int i = 0; i < input.size(); ++i) {
    if (i == input.size() - 1) {
      if (input[i] == input[0]) {
	sum += input[i];
      }
    } else {
      if (input[i] == input [i+1]) {
	sum += input[i];
      }
    }
  }
  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}
