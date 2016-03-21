#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::Push(int numbers)
{
	this->stack.push_back(numbers);
}

void Stack::Pop()
{
	if (this->stack.size() > 0) {
		stack.pop_back();
	}

	else 
	{
		cout << "Can not pop an empty Stack" << endl;

	}
}

void Stack::Print()
{
	if (this - stack.size() > 0)
	{
		cout << this->stack[stack.size() - 1] << endl;
	}
	else
	{
		cout << " Can not print from an empty stack!" << endl;
	}
}

int Stack::Peek()
{
	if (this->stack.size() > 0)
	{
		return this->stack[stack.size() - 1];
	}
	else
	{
		cout << "Can not peek and empty stack!" << endl;
		return 0;
	}

}
