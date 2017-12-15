#include <iostream>
#include <bitset>

int main() {
  long A_start = 783;
  long B_start = 325;
  long A_factor = 16807;
  long B_factor = 48271;
  long divisor = 2147483647;

  long a = (A_start * A_factor)%divisor;
  while (a%4 != 0) {
    a = (a* A_factor)%divisor;
  }
  long b = (B_start * B_factor)%divisor;
  while (b%8 != 0) {
    b = (b * B_factor)%divisor;
  }

  int count = 0;
  for (unsigned long i = 0; i < 5000000; ++i) {
    //kstd::cout << a << " " << b << std::endl;
    std::bitset<16> a_bits(a);
    std::bitset<16> b_bits(b);
    if (a_bits == b_bits) {
      ++count;
    }
    a = (a* A_factor)%divisor;
    while (a%4 != 0) {
      a = (a* A_factor)%divisor;
    }
    b = (b * B_factor)%divisor;
    while (b%8 != 0) {
      b = (b * B_factor)%divisor;
    }
  }
  std::cout << count << std::endl;
}
