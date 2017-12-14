#include <bitset>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

std::string knot_hash(const std::string &in);

int main() {
    std::string input;
    std::cin >> input;
    int totalCount = 0;
  for (unsigned int i = 0; i < 128; ++i) {
    std::string thisInput = input;
    thisInput += "-";
    thisInput += std::to_string(i);
    std::cout << thisInput << std::endl;
    std::string line;
    line = knot_hash(thisInput);
    std::cout << line << std::endl;
    std::string binary;
    for (unsigned int i = 0; i < line.size(); ++i) {
      std::string digit(1, line[i]);
      int n;
      std::istringstream(digit) >> std::hex >> n;
      std::bitset<4> bits(n);
      binary += bits.to_string();
    }
    std::cout << binary << std::endl;
    int count = 0;
    for (unsigned int i = 0; i < binary.size(); ++i) {
      if (binary[i] == '1') {
	count++;
      }
    }
    totalCount += count;
    std::cout << count << std::endl;
  }
  std::cout << totalCount << std::endl;
}



std::string knot_hash(const std::string &in) {
  //Read in input
  std::vector<int> lengths;
  char n;
  std::istringstream ss(in);
  while(ss.read(&n, 1)) {
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
  //for (unsigned int i = 0; i < lengths.size(); ++i) {
  //std::cout << lengths[i] << " ";
  //}
  //std::cout << std::endl;

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
  std::string output;
  std::stringstream outstream;
  for (unsigned int i = 0; i < dense_hash.size(); ++i) {
    outstream << std::hex << std::setw(2) << std::setfill('0') << dense_hash[i];
  }
  outstream >> output;
  return output;
}
