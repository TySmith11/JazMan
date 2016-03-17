#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::Push(int numbers)
{
	stack.push_back(numbers);
}

void Stack::Pop()
{
	stack.pop_back();
}


