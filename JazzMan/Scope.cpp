#include <iostream>
#include <string>
#include "Scope.h"
using namespace std;

Scope::Scope()
{
	this->CurrentScope = 0;
	this->callReturn = true;
	this->Passing = false;


}

int Scope::GetValue(string i)
{
	if (this->variables.size() != 0)
	{
		for (unsigned int j = 0; j < this->variables.size(); j++)
		{
			if (this->Passing == false && this->callReturn == false && this->variables[j].GetValue(i, CurrentScope) != "false")
			{
				return stoi(this->variables[j].GetValue(i, CurrentScope));
			}
			else if (this->Passing == true && this->callReturn == true && this->variables[j].GetValue(i, CurrentScope) != "false")
			{
				return stoi(this->variables[j].GetValue(i, CurrentScope + 1));
			}
			else if (this->Passing == true && this->callReturn == false && this->variables[j].GetValue(i, CurrentScope) != "false")
			{
				return stoi(this->variables[j].GetValue(i, CurrentScope));
			}
			else if (this->variables.size() - 1 == j)
			{
				return 0;
			}

		}
	}
	else
	{
		return 0;
	}
}


void Scope::SetValue(int varAdress, int value)
{
	if (varAdress != -1)
	{
		this->variables[varAdress].ChangeValue(value);
	}
	else
	{
		cout << "No name for variable" << endl;
	}
}

int Scope::GetAddress(string currentVariable)
{
	if (currentVariable != "")
	{
		if (this->variables.size() != 0)
		{
			for (unsigned int j = 0; j < this->variables.size(); j++)
			{
				if (this->Passing == false && this->callReturn == false && this->variables[j].ChangeValue(currentVariable, CurrentScope) != "false")
				{
					return j;
				}
				else if (this->Passing == true && this->callReturn == false && this->variables[j].ChangeValue(currentVariable, CurrentScope) != "false")
				{
					return j;
				}
				else if (this->variables.size() - 1 == j)
				{
					if (this->Passing == false && this->callReturn == false)
					{
						this->variables.push_back(Variables(currentVariable, 0, CurrentScope + 1));
						return j + 1;
					}
					else if (this->Passing == true && this->callReturn == false)
					{
						this->variables.push_back(Variables(currentVariable, 0, CurrentScope));
						return j + 1;
					}
					else if (this->Passing == true && this->callReturn == true)
					{
						this->variables.push_back(Variables(currentVariable, 0, CurrentScope));
						return j + 1;
					}
				}
			}
		}
		else
		{
			if (this->Passing == false && this->callReturn == false)
			{
				this->variables.push_back(Variables(currentVariable, 0, CurrentScope));
				return 0;
			}
			else if (this->Passing == true && this->callReturn == false)
			{
				this->variables.push_back(Variables(currentVariable, 0, CurrentScope));
				return 0;
			}
			else if (this->Passing == true && this->callReturn == true)
			{
				this->variables.push_back(Variables(currentVariable, 0, currentScope));
				return 0;
			}
		}
	}
	else
	{
		cout << "What variable name" << endl;
		return -1;
	}
}

void Scope::inecrmentScope() 
{
	this->CurrentScope++;
}

void Scope::decrementScope()
{
	this->CurrentScope--;

}

void Scope::CallReturn(bool callReturn)
{
	this->CallReturn = callReturn;
}

void Scope::paramPassing(bool Passing)
{
	this->Passing == Passing;
}