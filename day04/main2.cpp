#include <unordered_set>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

bool isAnagram(const std::string &a, const std::string &b) {
  if(a.size() != b.size()) {
    return false;
  }
  std::map<char, int> a_chars;
  std::map<char, int> b_chars;
  for (unsigned int i = 0; i < a.size(); ++i) {
    a_chars[a[i]]++;
    b_chars[b[i]]++;
  }
  std::map<char, int>::iterator a_itr = a_chars.begin();
  std::map<char, int>::iterator b_itr = b_chars.begin();
  for (unsigned int i = 0; i < a_chars.size(); ++i) {
    if(a_itr->first != b_itr->first || a_itr->second != b_itr->second) {
      return false;
    }
    ++a_itr;
    ++b_itr;
  }
  return true;

}
int main() {
  std::cout << "Enter input: ";
  //Number of valid passphrases
  int count = 0;
  std::string line;
  while(std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::unordered_set<std::string> input;
    std::string in;
    bool invalid = false;
    while (iss >> in && !invalid) {
      std::cout << in << " ";
      for (std::unordered_set<std::string>::iterator itr = input.begin(); itr != input.end(); ++itr) {
	if(isAnagram(in, *itr)) {
	  invalid = true;
	}
      }
      if(!input.insert(in).second) {
	invalid = true;
      }
    }
    if (!invalid) {
      ++count;
    }
    std::cout << count << std::endl;
  }
  std::cout << "There are: " << count << " valid passphrases" << std::endl;
  return 0;
}
