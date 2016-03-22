#ifndef STACK
#define STACK
#include <vector>


class Stack
{
public:
	void Pop(); //remove top of stack
	void Push(int numbers); //place on stack
	void Print(); //cout top of stack
	int Peek(); //view top of stack

private:
	std::vector<int> stack; //stack is really a vector of ints
};

#endif

