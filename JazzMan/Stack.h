#ifndef STACK
#define STACK
#include <vector>


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

