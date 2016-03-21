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

void Symbols::Readit(string FileName)
{
	FileReader FileReader(FileName, this->placeholder);
}

int Symbols::Whatdo(int postion)
{
	for (unsigned int i = postion; i < placeholder.size(); i++)
	{
		if (placeholder[i].state == "push")
		{
			this->stack.Push(stoi(this->placeholder[i].param));
		}
		if (placeholder[i].state == "show")
		{
			cout << placeholder[i].param << "\n";
		}
	
		if (placeholder[i].state == "rvalue")
		{
			this->stack.Push(this->scoping.GetValue(placeholder[i].param));
		}

		if (placeholder[i].state == "lvalue")
		{
			this->stack.Push(this->scoping.GetAddress(this->placeholder[i].param));
		}

		if (placeholder[i].state == "pop")
		{
			this->stack.Pop();
		}

		if (placeholder[i].state == ":=")
		{
			int a = stack.Peek();
			this->stack.Pop();
			int b = stack.Peek();
			this->stack.Pop();
			this->scoping.SetValue(b, a);
		}

		if (placeholder[i].state == "copy")
		{
			this->stack.Push(stack.Peek());
		}


		if (placeholder[i].state == "goto")
		{
			for (int j = 0; j < placeholder.size(); j++)
			{
				if (placeholder[j].state == "label" && placeholder[j].param == placeholder[i].param) { i = j; break;}
			}
		}

		if (placeholder[i].state == "gofalse")
		{
			int a;

			a = this->stack.Peek();
			this->stack.Pop();
			if (a == 0)
			{
				for (unsigned int j = 0; j < this->placeholder.size(); j++)
				if (placeholder[j].state == "lable" && placeholder[j].param == placeholder[i].param) { i = j; break; }
			}
		}

		if (placeholder[i].state == "gotrue")
		{
			int a;
			a = this->stack.Peek();
			this->stack.Pop();
			if (a != 0)
			{
				for (unsigned int j = 0; j < this->placeholder.size(); j++)
				{
					if (placeholder[j].state == "lable" && placeholder[j].param == placeholder[i].param) { i = j; break; }
				}
			}
		}

		if (placeholder[i].state == "halt")
		{
			return -1;
		}

		

		if (placeholder[i].state == "print")
		{
			this->stack.Print();
		}

		if (placeholder[i].state == "begin")
		{
			this->scoping.paramPassing(true);
			i = this->Whatdo(i + 1);
			continue;
		}

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

		if (placeholder[i].state == "return")
		{
			this->scoping.decrementScope();
			this->scoping.CallReturn(true);
			this->scoping.paramPassing(true);
			if (postion != 0) { return i; }

			else { cout << "not in call" << endl; }

		}

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

void Symbols::doLogic(int i)
{
	if (this->placeholder[i].state == "+" || this->placeholder[i].state == "-" || this->placeholder[i].state == "/" || this->placeholder[i].state == "*" || this->placeholder[i].state == "<" || this->placeholder[i].state == ">" || this->placeholder[i].state == "div" || this->placeholder[i].state == "&" || this->placeholder[i].state == "|" || this->placeholder[i].state == "<>" || this->placeholder[i].state == "<=" || this->placeholder[i].state == ">=" || this->placeholder[i].state == "=") {

		int a;
		int b;
		b = this->stack.Peek();
		this->stack.Pop();
		a = this->stack.Peek();
		this->stack.Pop();

		if (placeholder[i].state == "+")
		{
			this->stack.Push(a + b);
		}

		if (placeholder[i].state == "-")
		{
			this->stack.Push(a - b);
		}

		if (placeholder[i].state == "*")
		{
			this->stack.Push(a * b);
		}

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

		if (placeholder[i].state == "!")
		{
			int a;
			a = this->stack.Peek();
			this->stack.Pop();

			if (a == 1)
				this->stack.Push(0);
			else if (a == 0)
				this->stack.Push(1);
		}

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