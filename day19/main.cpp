#include <iostream>
#include <vector>

int main () {
  std::vector<std::vector<char> > diagram;
  std::string line;
  while(std::getline(std::cin, line)) {
    std::vector<char> tmp;
    for (unsigned int i = 0; i < line.length(); ++i) {
      tmp.push_back(line[i]);
    }
    diagram.push_back(tmp);
  }

  //Print for debugging
  //for (unsigned int i = 0; i < diagram.size(); ++i) {
    //for (unsigned int j = 0; j < diagram[i].size(); ++j) {
      //std::cout << diagram[i][j];
    //}
    //std::cout << std::endl;
  //}

  std::string answer;
  char direction = 'd'; 
  int x = 0;
  int y = 0;

  //get to starting point
  for (;x < diagram[0].size(); ++x) {
    if (diagram[0][x] == '|') {
      break;
    }
  }
  
  //Part 2:
  int counter = 0;
  //follow diagram
  while (x>=0 && y>=0 && x<diagram[y].size() && y<diagram.size()) {
    ++counter;
   switch(direction) {
     case 'u': --y;
	     break;
     case 'd': ++y;
	       break;
     case 'l': --x;
	       break;
     case 'r': ++x;
	       break;
   }
   if (diagram[y][x] == '|' || diagram[y][x] == '-') {
     continue;
   } else if (diagram[y][x] == '+') {
     if (direction == 'u' || direction == 'd') {
       if (x >= 1 && diagram[y][x-1] != ' ') {
	 direction = 'l';
       } else {
	 direction = 'r';
       }
     } else {
       if (y >=1 && diagram[y-1][x] != ' ') {
	 direction = 'u';
       } else {
	 direction = 'd';
       }
     }
   } else if (diagram[y][x] != ' ') {
     answer += diagram[y][x];
   } else {
     std::cout << answer << " " << counter << std::endl;
     break;
   }
  }
}
