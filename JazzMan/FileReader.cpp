#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "FileReader.h"
#include "Symbols.h"


using namespace std;

//Read a file
FileReader::FileReader(string FileName, vector<Parsing> &placeholder)
{
	ifstream file(FileName);
	string line;
	int index = 0;
	bool ignoreline = false;
	
	//If file opens get a line from the file
	if (file.good())
	{
		while (getline(file, line))
		{
			line.erase(line.find_last_not_of(" \n\t\r") + 1);
			line.erase(0, line.find_first_not_of(" \n\t\r"));
			//Test for a comment block
			if (line.find("/*") != string::npos)
			{
				ignoreline = true;
			}
			//Test for blank line
			if (line == "")
			{
				continue;
			}
			//Else if not comment or blank then stream into TempCode
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
			//End of comment block in file
			else if (line.find("*/") != string::npos)
			{
				ignoreline = false;
			}
		}
	}
	//Error Condition unable to read or find file
	else
	{
		cout << "Cannot find file\n";
	}
	file.close();
	

	
}
