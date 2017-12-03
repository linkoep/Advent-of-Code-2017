#include <cassert>
#include <iostream>
#include <cmath>
#include <map>

int main() {
  int location;
  std::cout << "Enter location: ";
  std::cin >> location;
  int direction = 0;
  int x = 0;
  int y = 0;

  //Keep track of values
  std::map<std::pair<int, int>, int> spiral;
  spiral.insert(std::make_pair(std::make_pair(0,0), 1));

  for (unsigned int n = 1; n < location; ++n) {
    //Moving right
    if (direction == 0) {
      if (std::abs(x) <= std::abs(y) ) {
	++x;
      } else {
	++direction;
	++y;
      }
      //moving up
    } else if (direction == 1) {
      if (std::abs(y) < std::abs(x) ) {
	++y;
      } else {
	++direction;
	--x;
      }
      //moving left
    } else if (direction == 2) {
      if (std::abs(x) < std::abs(y) ) {
	--x;
      } else {
	++direction;
	--y;
      }
      //moving down
    } else {
      if (std::abs(y) < std::abs(x) ) {
	--y;
      } else {
	direction = 0;
	++x;
      }
    } 
    //Update values;
    int sum = 0;
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
	if (i == j && i == 0) {
	  continue;
	}
	std::map<std::pair<int, int>, int>::iterator itr;
	itr = spiral.find(std::make_pair(x+i,y+j));
	if (itr != spiral.end()) {
	  //std::cout << "Added: " << itr->second << "from: (" << x+i << ", " << y +j << ")" << std::endl;
	  sum += itr->second;
	}
      }
    }
    spiral.insert(std::make_pair(std::make_pair(x,y), sum));
    std::cout << sum << std::endl;
    if (sum > location) {
      break;
    }


  }
}
