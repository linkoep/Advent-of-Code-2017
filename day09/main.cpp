#include <iostream>
#include <vector>

int main() {
  std::vector<int> scores(1000); //Arbitrarily large, hopefully no more than 100 levels
  int level = 0;
  int garbage = 0;
  char c;
  while (std::cin >> c) {
    if (c == '{') { ++level; }
    else if (c == '}') {
      scores[level]++;
      --level;
    } else if (c == '<') {
      while (std::cin>> std::noskipws>>c && c != '>') {
	if (c== '!') { std::cin >> c; }
	else { ++garbage;}
      }
    }
  }
  int score = 0;
  for (unsigned int i = 0; i < scores.size(); ++i) {
    if (scores[i] != 0) {
      score += (i * scores[i]);
      std::cout << i << "x" << scores[i] << " ";
    }
  }
  std::cout << std::endl << score << std::endl;
  std::cout << garbage << std::endl;
}
