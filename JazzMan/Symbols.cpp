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
			this->stack.Push(this->scoping.GetValue(this->placeholder[i].param));
		}

		if (placeholder[i].state == "pop")
		{

		}

		if (placeholder[i].state == ":=")
		{

		}

		if (placeholder[i].state == "copy")
		{

		}


		if (placeholder[i].state == "goto")
		{
			for (int j = 0; j < placeholder.size(); j++)
			{
				if (placeholder[j].state == "lable" && placeholder[j].param == placeholder[i].param) { i = j; }
			}
		}

		if (placeholder[i].state == "gofalse")
		{

		}

		if (placeholder[i].state == "gotrue")
		{

		}

		if (placeholder[i].state == "halt")
		{

		}

		if (placeholder[i].state == "+")
		{
		
		}

		if (placeholder[i].state == "-")
		{

		}

		if (placeholder[i].state == "*")
		{

		}

		if (placeholder[i].state == "/")
		{

		}

		if (placeholder[i].state == "div")
		{

		}

		if (placeholder[i].state == "&")
		{

		}

		if (placeholder[i].state == "!")
		{

		}

		if (placeholder[i].state == "|")
		{

		}

		if (placeholder[i].state == "<>")
		{

		}

		if (placeholder[i].state == "<=")
		{

		}

		if (placeholder[i].state == ">=")
		{

		}

		if (placeholder[i].state == "<")
		{

		}

		if (placeholder[i].state == ">")
		{

		}

		if (placeholder[i].state == "=")
		{

		}

		if (placeholder[i].state == "print")
		{

		}

		if (placeholder[i].state == "begin")
		{

		}

		if (placeholder[i].state == "end")
		{

		}

		if (placeholder[i].state == "return")
		{

		}

		if (placeholder[i].state == "call")
		{

		}
	}
	return -1;
}

void Symbols::doLogic(int i)
{

}