#ifndef STACK
#define STACK
#include <vector>
#include "Symbols.h"

class Stack
{
public:
	void Pop();
	void Push(int numbers);
	void Print();
	int Peek();

private:
	std::vector<int> stack;
};

#endif

