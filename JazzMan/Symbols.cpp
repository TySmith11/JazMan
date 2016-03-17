#include <iostream>
#include <string>
#include <vector>
#include "Symbols.h"
#include "Parsing.h"
using namespace std;

void Symbols::Whatdo(vector<Parsing>placeholder)
{
	for (int i = 0; i < placeholder.size(); i++)
	{
		if (placeholder[i].state == "show")
		{
			cout << placeholder[i].param << "\n";
		}
	}
}