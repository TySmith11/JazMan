#include <iostream>
#include <string>
#include "FileReader.h"
using namespace std;



int main()
{
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
			FileReader FileReader(FileName);

		}

		cout << "press a key to exit";
		cin >> key;




}
