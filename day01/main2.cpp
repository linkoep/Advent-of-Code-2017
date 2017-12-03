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
    int num_steps = input.size() / 2;
    int compare = i + num_steps;
    if (compare >= input.size()) {
      compare -= input.size();
    }
    if (input[i] == input[compare]) {
      sum += input[i];
    }
  }
  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}
