#include <vector>
#include <iomanip>
#include <string>
#include <iostream>

int main() {
  //Read in input
  std::vector<int> lengths;
  char n;
  while(std::cin.read(&n, 1)) {
    if (n != '\n') {
      lengths.push_back((int)n);
    }
  }
  lengths.push_back(17);
  lengths.push_back(31);
  lengths.push_back(73);
  lengths.push_back(47);
  lengths.push_back(23);

  //Print input for debugging
  for (unsigned int i = 0; i < lengths.size(); ++i) {
    std::cout << lengths[i] << " ";
  }
  std::cout << std::endl;

  //Set up list
  std::vector<int> list;
  int current = 0;
  int skip_size = 0;
  for (unsigned int i = 0; i < 256; ++i) {
    list.push_back(i);
  }

  //Calculate Sparse Hash
  for (unsigned int round = 0; round < 64; ++round) {
    //One round of shuffling
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
  }

  //Calculate dense hash
  std::vector<int> dense_hash;
  for(unsigned int i = 0; i < 16; ++i) {
    int hash = list[i*16];
    for (unsigned int j = 1; j < 16; ++j) {
      hash ^= list[i*16+j];
    }
    dense_hash.push_back(hash);
  }

  //Output as hexadecimal
  for (unsigned int i = 0; i < dense_hash.size(); ++i) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << dense_hash[i];
  }
  std::cout << std::endl;
}
