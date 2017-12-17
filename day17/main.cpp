#include <list>
#include <iostream>
#define STEP_LENGTH 355

int main() {
  std::list<int> buffer;
  buffer.push_back(0);
  std::list<int>::iterator itr = buffer.begin();
  for (unsigned int i = 1; i <= 2017; ++i) {
    for (unsigned int j = 1; j < STEP_LENGTH; ++j) {
      ++itr;
      if (itr == buffer.end()) {
	itr = buffer.begin();
      }
    }
    buffer.insert(++itr, i);
      if (itr == buffer.end()) {
	itr = buffer.begin();
      }
    //for (std::list<int>::iterator printer = buffer.begin(); printer != buffer.end(); ++printer) {
      //std::cout << *printer << " ";
    //}
    //std::cout << std::endl;
  }
  std::cout << *itr << std::endl;
}
