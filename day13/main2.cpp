#include <iostream>
#include <vector>

int main() {
  std::vector<int> firewall(100, -1);
  int layer, range;
  char x;
  while (std::cin >> layer >> x >> range) {
    firewall[layer] = range;
  }
  for (unsigned int delay = 0; ; ++delay) {
    bool caught = false;
    for (unsigned int i = 0; i < firewall.size(); ++i) {
      if (firewall[i] == -1) {
	continue;
      }
      int layer_range = firewall[i];
      int period = (layer_range-1)*2;
      int position = (i+delay)%period;
      if (position > layer_range-1) {
	position = (layer_range-1) - ((i+delay)-layer_range);
      }
      if (position == 0) {
	caught = true;
	break;
      }
    }
    //std::cout << severity << std::endl;
    if (!caught) {
      std::cout << delay << std::endl;
      break;
    }
  }
}
