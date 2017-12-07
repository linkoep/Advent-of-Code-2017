#include <cmath>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <list>

bool compare_vect(const std::vector<int> &a, const std::vector<int> &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (unsigned int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  //Read input
  std::vector<int> banks;
  int n;
  while(std::cin >> n) {
    banks.push_back(n);
  }
  int count = 0;
  std::list<std::vector<int> > history;
  //Loop operation
  bool match = false;
  std::vector<int> to_match;
  while (true) {
    for (unsigned int i = 0; i < banks.size(); ++i) {
      std::cout << banks[i] << " ";
    }
    std::cout << std::endl;
    if (compare_vect(banks, to_match)) {
      break;
    }
    if (!match) {
      for (std::list<std::vector<int> >::iterator itr = history.begin(); itr !=
	  history.end(); ++itr) {
	if (compare_vect(banks, *itr)) {
	  match = true;
	  count = 0;
	  to_match = banks;
	  break;
	}
      }
    }
    history.push_back(banks);
    int max = -1;
    int index = -1;
    for (unsigned int i = 0; i < banks.size(); ++i) {
      if (banks[i] > max) {
	max = banks[i];
	index = i;
      }
    }
    assert(index >= 0 && index < banks.size());
    banks[index] = 0;
    int current;
    for (unsigned int i = 0; i < max; ++i) {
      current = (index + 1 + i) % banks.size();
      ++banks[current];
    }
    ++count;
  }
  std::cout << count << " Steps" << std::endl;
}
