#include <iostream>
#define NUM_STEPS 355;

int main() {
  int pos = 0;
  int size = 0;
  int touching_zero;
  for (unsigned int i = 0; i < 50000000 ; ++i) {
    if (pos == 1) {
      touching_zero = i;
    }
    ++size;
    pos += NUM_STEPS;
    pos %= size;
    ++pos;
  }
      std::cout << touching_zero << std::endl;
}
