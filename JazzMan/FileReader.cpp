#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "FileReader.h"
#include "Symbols.h"


using namespace std;


FileReader::FileReader(string FileName)
{
	ifstream file(FileName);
	string line;
	int index = 0;
	bool ignoreline = false;
	vector<Parsing> placeholder;

	if (file.good())
	{
		while (getline(file, line))
		{
			line.erase(line.find_last_not_of(" \n\t\r") + 1);
			line.erase(0, line.find_first_not_of(" \n\t\r"));
			if (line.find("/*") != string::npos)
			{
				ignoreline = true;
			}
			if (line == "")
			{
				continue;
			}
			else if (ignoreline == false)
			{
				stringstream ss;
				Parsing TempCode;

				ss << line;
				ss >> TempCode.state;
				if (TempCode.state.size() < line.size())
					TempCode.param = line.substr(TempCode.state.size() + 1, line.npos);
				else
					TempCode.param = "";
				placeholder.push_back(TempCode);
				
				index++;
			}
			else if (line.find("*/") != string::npos)
			{
				ignoreline = false;
			}
		}
	}

	else
	{
		cout << "Cannot find file";
	}
	file.close();
	
	Symbols(placeholder);
	
}
