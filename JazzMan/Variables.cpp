#include "Variables.h"
#include <string>

Variables::Variables(std::string setVariable, int setValue, int setScope)
{
	this->varname = setVariable;
	this->value = setValue;
	this->variableScope = setScope;
}

std::string Variables::GetValue(std::string getVariable, int currentScope)
{
	if (getVariable == this->varname && currentScope == this->variableScope)
	{
		return std::to_string(this->value);
	}
	else
	{
		return "false";
	}
}
	void Variables::ChangeValue(int value)
	{
		this->value = value;
	}
