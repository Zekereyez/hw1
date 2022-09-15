/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {
	ULListStr *first = new ULListStr();
	ULListStr *second = new ULListStr();
	// testing adding into empty list
	// fill up the arrays and see 
	for (int i = 0; i < 30; ++i) {
		std::string s = "Test";
		std::string result;
		result = s + std::to_string(i);
		first->push_front(result);
		second->push_back(result);
	}
  return 0;
}
