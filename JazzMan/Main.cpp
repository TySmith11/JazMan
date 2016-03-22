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

	//Prompt for Jaz File
	cout << "What file do you want to load: ";
	getline(cin, FileName);

	//Terminate if "EXIT" else attempt to load file
	if (FileName == "Exit")
	{
		return false;
	}
	else
	{
		symbol.Readit(FileName);

	}

	//Start main loop of decision making
	symbol.Whatdo(0);

}

//Loop program over and over prompting for input file
int main()
{
	while (running());
	return 0;
}
