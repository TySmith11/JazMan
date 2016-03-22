#include "Variables.h"
#include <string>

//Set Method
Variables::Variables(std::string setVariable, int setValue, int setScope)
{
	this->varname = setVariable;
	this->value = setValue;
	this->variableScope = setScope;
}

//Get method
std::string Variables::GetValue(std::string getVariable, int currentScope)
{
	//If this variable and scope are the current return this value else false
	if (getVariable == this->varname && currentScope == this->variableScope)
	{
		return std::to_string(this->value);
	}
	else
	{
		return "false";
	}
}

//Change the value
void Variables::ChangeValue(int value)
{
	this->value = value;
}
