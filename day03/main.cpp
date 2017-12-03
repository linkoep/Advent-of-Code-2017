#include <iostream>
#include <cmath>
#include <vector>

int main() {
  int location;
  std::cout << "Enter location: ";
  std::cin >> location;
  int direction = 0;
  int x = 0;
  int y = 0;
  for (unsigned int i = 1; i < location; ++i) {
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
  }
  std::cout << location << " is at: " << "(" << x << ", " << y << ")" << std::endl;
  std::cout << "Requires: " << std::abs(x) + std::abs(y) << " steps to get to center" << std::endl;
}
