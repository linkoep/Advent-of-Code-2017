#include <iostream>
#include <vector>

int main() {
  int severity = 0;
  std::vector<int> firewall(100, -1);
  int layer, range;
  char x;
  while (std::cin >> layer >> x >> range) {
    firewall[layer] = range;
  }
  for (unsigned int i = 0; i < firewall.size(); ++i) {
    if (firewall[i] == -1) {
      continue;
    }
    int layer_range = firewall[i];
    int period = (layer_range-1)*2;
    int position = i%period;
    if (position > layer_range-1) {
      position = (layer_range-1) - (i-layer_range);
    }
    if (position == 0) {
      severity += i * layer_range;
    }
  }
  std::cout << severity << std::endl;
}
