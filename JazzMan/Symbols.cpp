#include <iostream>
#include <string>
#include <vector>
#include "Symbols.h"
#include "Parsing.h"
#include "FileReader.h"
#include "Scope.h"
#include "Stack.h"
#include "FileReader.h"
using namespace std;

//Read the file
void Symbols::Readit(string FileName)
{
	FileReader FileReader(FileName, this->placeholder);
}

//Stack manipulators, flow and output
int Symbols::Whatdo(int postion)
{
	for (unsigned int i = postion; i < placeholder.size(); i++)
	{
		//Push value to stack
		if (placeholder[i].state == "push")
		{
			this->stack.Push(stoi(this->placeholder[i].param));
		}
		
		//Prints rest of line
		if (placeholder[i].state == "show")
		{
			cout << placeholder[i].param << "\n";
		}
		
		//Pushed contents of data to stack
		if (placeholder[i].state == "rvalue")
		{
			this->stack.Push(this->scoping.GetValue(placeholder[i].param));
		}

		//Pushes address of data to stack
		if (placeholder[i].state == "lvalue")
		{
			this->stack.Push(this->scoping.GetAddress(this->placeholder[i].param));
		}

		//Removes value from stack
		if (placeholder[i].state == "pop")
		{
			this->stack.Pop();
		}

		//Stack top is placed by the lvalue below it and both are popped
		if (placeholder[i].state == ":=")
		{
			int a = stack.Peek();
			this->stack.Pop();
			int b = stack.Peek();
			this->stack.Pop();
			this->scoping.SetValue(b, a);
		}

		//Pushes a copy of top of stack to stack
		if (placeholder[i].state == "copy")
		{
			this->stack.Push(stack.Peek());
		}

		//Go to label in file
		if (placeholder[i].state == "goto")
		{
			for (int j = 0; j < placeholder.size(); j++)
			{
				if (placeholder[j].state == "label" && placeholder[j].param == placeholder[i].param) { i = j; break;}
			}
		}

		//Pops the top value of the stack and jumps if it is zero
		if (placeholder[i].state == "gofalse")
		{
			int a;

			a = this->stack.Peek();
			this->stack.Pop();
			if (a == 0)
			{
				for (unsigned int j = 0; j < this->placeholder.size(); j++)
				if (placeholder[j].state == "label" && placeholder[j].param == placeholder[i].param) { i = j; break; }
			}
		}

		//Pops the top value of the stack and jumps if it is nonzero
		if (placeholder[i].state == "gotrue")
		{
			int a;
			a = this->stack.Peek();
			this->stack.Pop();
			if (a != 0)
			{
				for (unsigned int j = 0; j < this->placeholder.size(); j++)
				{
					if (placeholder[j].state == "label" && placeholder[j].param == placeholder[i].param) { i = j; break; }
				}
			}
		}

		//Stops execution
		if (placeholder[i].state == "halt")
		{
			return -1;
		}
		
		//Writes top of the stack contents to output device
		if (placeholder[i].state == "print")
		{
			this->stack.Print();
		}

		//Marks the beginning of parameter passing and subroutine call
		if (placeholder[i].state == "begin")
		{
			this->scoping.paramPassing(true);
			i = this->Whatdo(i + 1);
			continue;
		}

		//Marks the end of parameter passing and subroutine call
		if (placeholder[i].state == "end")
		{
			this->scoping.CallReturn(false);
			this->scoping.paramPassing(false);
			if (postion != 0)
			{
				return i;
			}
			else
			{
				cout << " Not in subroutine " << endl;
			}
		}

		//Returns from subroutine
		if (placeholder[i].state == "return")
		{
			this->scoping.decrementScope();
			this->scoping.CallReturn(true);
			this->scoping.paramPassing(true);
			if (postion != 0) { return i; }

			else { cout << "not in call" << endl; }

		}

		//Subroutine call
		if (placeholder[i].state == "call")
		{
			this->scoping.inecrmentScope();
			this->scoping.paramPassing(false);
			for (unsigned int j = 0; j < this->placeholder.size(); j++)
			{
				if (this->placeholder[j].state == "label" && this->placeholder[j].param == placeholder[i].param)
				{
					this->Whatdo(j);
					break;
				}
			}
		}
		this->doLogic(i);
	}
	return -1;
}

//Arithmetic and Logical Operations
void Symbols::doLogic(int i)
{
	//Check if state is an operation
	if (this->placeholder[i].state == "+" || this->placeholder[i].state == "-" || this->placeholder[i].state == "/" || this->placeholder[i].state == "*" || this->placeholder[i].state == "<" || this->placeholder[i].state == ">" || this->placeholder[i].state == "div" || this->placeholder[i].state == "&" || this->placeholder[i].state == "|" || this->placeholder[i].state == "<>" || this->placeholder[i].state == "<=" || this->placeholder[i].state == ">=" || this->placeholder[i].state == "=" || this->placeholder[i].state == "!") {

		int a;
		int b;
		//Set B
		b = this->stack.Peek();
		this->stack.Pop();
		//Set if not a single value input
		if (placeholder[i].state != "!")
		{
			a = this->stack.Peek();
			this->stack.Pop();
		}

		//Add two values
		if (placeholder[i].state == "+")
		{
			this->stack.Push(a + b);
		}

		//Subtract two values
		if (placeholder[i].state == "-")
		{
			this->stack.Push(a - b);
		}

		//Multiply two values
		if (placeholder[i].state == "*")
		{
			this->stack.Push(a * b);
		}

		//Divide two values
		if (placeholder[i].state == "/")
		{
			if (b != 0)
			{
				this->stack.Push(a / b);
			}
			else
			{
				cout << "cannot divid by 0" << endl;
			}
		}

		//Modulus operation
		if (placeholder[i].state == "div")
		{
			if (b != 0)
			{
				this->stack.Push(a % b);
			}

			else
			{
				cout << "cannot divid by 0" << endl;
			}
		}

		//Logical AND
		if (placeholder[i].state == "&")
		{
			if (a == 1 && b == 1)
			{
				this->stack.Push(1);
			}
			else
			{
				this->stack.Push(0);
			}

		}
		//Logical Negation
		if (placeholder[i].state == "!")
		{

			if (b == 1)
			
				this->stack.Push(0);
			
			else if (b == 0)
			
				this->stack.Push(1);
			
		}
		
		//Logical OR
		if (placeholder[i].state == "|")
		{
			if (a == 1 || b == 1)
			{
				this->stack.Push(1);
			}
			else
			{
				this->stack.Push(0);
			}
		}

		//1 if A != B else 0
		if (placeholder[i].state == "<>")
		{
			if (a == b)
			{
				this->stack.Push(0);
			}
			else
			{
				this->stack.Push(1);
			}
		}

		//1 if A <= B else 0
		if (placeholder[i].state == "<=")
		{
			if (a <= b)
			{
				this->stack.Push(1);
			}
			else
			{
				this->stack.Push(0);
			}
		}

		//1 if A >= B else 0
		if (placeholder[i].state == ">=")
		{
			if (a >= b)
			{
				this->stack.Push(1);
			}
			else
			{
				this->stack.Push(0);
			}
		}

		//1 if A < B else 0
		if (placeholder[i].state == "<")
		{
			if (a < b)
			{
				this->stack.Push(1);
			}
			else
			{
				this->stack.Push(0);
			}
		}

		//1 if A < B else 0
		if (placeholder[i].state == ">")
		{
			if (a > b)
			{
				this->stack.Push(1);
			}
			else
			{
				this->stack.Push(0);
			}
		}

		//1 if A <= B else 0
		if (placeholder[i].state == "=")
		{
			if (a != b)
			{
				this->stack.Push(0);
			}
			else
			{
				this->stack.Push(1);
			}
		}
	}
}