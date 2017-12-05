#include <vector>
#include <iostream>

int main() {
  int in;
  std::vector<int> input;
  while(std::cin >> in) {
    input.push_back(in);
  }
  int count = 0;
  int next = input[0];
  int current = 0;
  while(current > -1 && current < input.size()) {
    //for (unsigned int i = 0; i < input.size(); ++i) {
      //if (i == current) {
        //std::cout << "(" << input[i] << ") ";
      //} else {
        //std::cout << input[i] << " ";
      //}
    //}
    //std::cout << std::endl;
    next = input[current];
    input[current]++;
    current += next;
    ++count;
  }
  std::cout << count << " steps" << std::endl;
}
