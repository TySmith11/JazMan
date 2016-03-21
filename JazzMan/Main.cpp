#include <iostream>
#include <string>
#include "Symbols.h"
using namespace std;


bool running();

bool running()
{
	Symbols symbol;
	string key;
	string FileName = "";

	cout << "what file do you want to load: ";
	getline(cin, FileName);



	if (FileName == "Exit")
	{
		return false;
	}

	else
	{
		symbol.Readit(FileName);

	}

	symbol.Whatdo(0);

}


int main()
{
	while (running());
	return 0;
}
