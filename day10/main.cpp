#include <vector>
#include <string>
#include <iostream>

int main() {
  std::vector<int> lengths;
  int n;
  char x;
  while(std::cin >> n >> x) {
    lengths.push_back(n);
  }
  std::cin >> n;
  lengths.push_back(n);

  std::vector<int> list;
  int current = 0;
  int skip_size = 0;

  for (unsigned int i = 0; i < 256; ++i) {
    list.push_back(i);
  }

  for (unsigned int i = 0; i < lengths.size(); ++i) {
    ////Print for debugging
    //for (unsigned int k = 0; k < list.size(); ++k) {
      //if (k == current) {
	//std::cout << "[" << list[k] << "]" << " ";
      //} else {
	//std::cout << list[k] << " ";
      //}
    //}
    //std::cout << std::endl;
    int end = current + lengths[i] % list.size();
    for (int j = 0; j < lengths[i]/2; ++j) {
      int swap_a = (current + j)%list.size();
      int swap_b = (end +list.size() - j-1)%list.size();
      std::swap(list[swap_a], list[swap_b]);
    }
    current += lengths[i] + skip_size;
    current %= list.size();
    ++skip_size;
  }
  ////Print for debugging
  //for (unsigned int k = 0; k < list.size(); ++k) {
    //if (k == current) {
      //std::cout << "[" << list[k] << "]" << " ";
    //} else {
      //std::cout << list[k] << " ";
    //}
  //}
  //std::cout << std::endl;
  std::cout << list[0] * list[1] << std::endl;
}
