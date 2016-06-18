#ifndef CALCULATOR_R
#define CALCULATOR_R
#include <iostream>
#include <sstream>
#include <string>
#include <new>
#include <cstdlib>
#include "stack.h"


class Calculator {

private:
	Stack stack;
	std::string operation;

public:
	bool check_correctness();
	void add();
	void subtract();
	void multiply();
	void enter_operation() { getline(std::cin, operation); };
	int  result();
};


#endif
