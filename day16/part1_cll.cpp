#include <iostream>

struct Node {
  Node(char a) : value(a), left(NULL), right(NULL) {}
  char value;
  Node* left;
  Node* right;
};
int main() {
  Node* current = new Node('a');
  Node* root = current;
  for (unsigned int i = 0; i < 15; ++i) {
    current->right = new Node('a' +i +1);
    current->right->left = current;
    current = current->right;
  }
  current->right = root;
  root->left = current;
  current = NULL;


  char c;
  while(std::cin >> c) {
    if (c=='s') {
      int spin;
      std::cin >> spin;
      for (unsigned int i = 0; i < spin; ++i) {
	root = root->left;
      }
    } else if (c=='x') {
      int a, b;
      std::cin >> a >> c >> b;
      Node* a_ptr = root;
      Node* b_ptr = root;
      for (unsigned int i = 0; i < a; ++i) {
	a_ptr = a_ptr->right;
      }
      for (unsigned int i = 0; i < b; ++i) {
	b_ptr = b_ptr->right;
      }
      std::swap(a_ptr->value, b_ptr->value);
    } else if (c=='p'){
      char a, b;
      std::cin >> a >> c >> b;
      Node* a_ptr = root;
      Node* b_ptr = root;
      while (a_ptr->value!=a) {
	a_ptr = a_ptr->right;
      }
      while (b_ptr->value!=b) {
	b_ptr = b_ptr->right;
      }
      std::swap(a_ptr->value, b_ptr->value);
    }
    std::cin >> c;
  }

  Node* itr = root;
  for (unsigned int i = 0; i < 16; ++i) {
    std::cout << itr->value;
    itr = itr->right;
  }
  std::cout <<std::endl;
}
