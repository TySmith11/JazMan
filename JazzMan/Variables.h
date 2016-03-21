#ifndef VARIABLES
#define VARIABLES
#include <string>

class Variables
{
private:
	int variableScope, value; //holds scope of variable and the value
	std::string varname;	 //holds any variable name

public:
	Variables(std::string setVariable, int setValue, int SetScope);
	std::string GetValue(std::string GetVariable, int CurrentScope);
	void ChangeValue(int value);
	
};
#endif

