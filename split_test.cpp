#include "split.h"
#include <iostream>

using namespace std;

int main() {
  Node *first = new Node(1, nullptr);
  Node *second = new Node(2, first);
  Node *third = new Node(3, second);
  // first->next = second;
  // second->next = third;
  Node *odds = nullptr;
  Node *evens = nullptr;

  split(third, odds, evens);
  
  while (odds != nullptr) {
    cout << "In odds" << endl;
    cout << odds->value << endl;
    odds = odds->next;
  }
  while (evens != nullptr) {
    cout << "In evens" << endl;
    cout << evens->value << endl;
    evens = evens->next;
  }
}