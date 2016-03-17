#include <iostream>
#include <string>
#include <vector>
#include "Symbols.h"
#include "Parsing.h"
#include "FileReader.h"
using namespace std;

void Symbols::Whatdo(vector<Parsing>placeholder)
{
	for (int i = 0; i < placeholder.size(); i++)
	{
		if (placeholder[i].state == "show")
		{
			cout << placeholder[i].param << "\n";
		}
	
		if (placeholder[i].state == "rvalue")
		{

		}

		if (placeholder[i].state == "lvalue")
		{

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

		if (placeholder[i].state == "lable")
		{

		}

		if (placeholder[i].state == "goto")
		{

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
}