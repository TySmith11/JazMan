#include <iostream>
#include "Stack.h"

using namespace std;

//Save an int to the stack
void Stack::Push(int numbers)
{
	this->stack.push_back(numbers);
}

//Remove an int from the stack
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

//cout the top of the stack
void Stack::Print()
{
	if (this->stack.size() > 0)
	{
		cout << this->stack[stack.size() - 1] << endl;
	}
	else
	{
		cout << " Can not print from an empty stack!" << endl;
	}
}

//View the top of the stack
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
