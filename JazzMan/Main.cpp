#include <iostream>
#include <string>
#include "Symbols.h"
using namespace std;



int main()
{
	Symbols symbol;
	string key;
	string FileName = "";
	cout << "what file do you want to load: ";
		getline(cin, FileName);
		
		if (FileName == "Exit")
		{
			return 0;
		}

		else
		{
			symbol.Readit(FileName);
			
		}

		cout << "press a key to exit";
		cin >> key;




}
