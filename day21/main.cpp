#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

std::string makeString(const std::vector<std::string> &pattern) {
  std::string answer;
  for (unsigned int i = 0; i < pattern.size(); ++i) {
    answer += pattern[i];
    answer+="/";
  }
  answer = answer.substr(0, answer.size()-1);
  return answer;
}

std::set<std::string> findRots(const std::string& pattern) {
  std::reverse(pattern.begin(), pattern.begin()+pattern.find('/'));
}

int main() {
  std::unordered_map<std::string, std::string> rules;
  std::string line;
  while (std::getline(std::cin, line)) {
    std::string key, arrow, value;
    std::istringstream iss (line);
    iss >> key >> arrow >> value;
    assert (arrow == "=>");
  }

  std::vector<std::string> image;
  image.push_back(".#.");
  image.push_back("..#");
  image.push_back("###");
  for (unsigned int i = 0; i < 5; ++i) {
    std::vector<std::string> patterns;
    if (image.size()%2 == 0) {
      for (unsigned int col = 0; col < image.size()-1; col+=2) {
	for (unsigned int row = 0; row < image.size()-1; row+=2) {
	  std::vector<std::string> pattern_v;
	  for (unsigned int subrow = 0; subrow < 3; ++subrow) {
	  std::string row = image[row+subrow].substr(col, col+2);

	  }
	  patterns.push_back(pattern);
	}
      }
    } else {
      assert(image.size()%3 == 0);
      for (unsigned int col = 0; col < image.size()-2; col+=3)	 {
	for (unsigned int row = 0; row < image.size()-2; row+=3) {
	  std::string pattern;
	  pattern+=image[row].substr(col, col+3);
	  pattern+="/";
	  pattern+=image[row+1].substr(col, col+3);
	  pattern+="/";
	  pattern+=image[row+2].substr(col, col+3);
	  //std::cout << pattern << std::endl;
	  patterns.push_back(pattern);
	}
      }
    }
    for (unsigned int i = 0; i < patterns.size(); ++i) {
      std::unordered_set<std::string> rotations = findRots(patterns[i]);
    }
  }
}
