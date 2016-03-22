#include <iostream>
#include <string>
#include "Scope.h"
using namespace std;

Scope::Scope()
{
	this->CurrentScope = 0;
	this->callReturn = false;
	this->Passing = false;


}

//Returns the value of a variable
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
			else if (this->Passing == true && this->callReturn == true && this->variables[j].GetValue(i, CurrentScope + 1) != "false")
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

//Sets the value for variable
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

//Returns the address of a variable
int Scope::GetAddress(string currentVariable)
{
	if (currentVariable != "")
	{
		if (this->variables.size() != 0)
		{
			for (unsigned int j = 0; j < this->variables.size(); j++)
			{
				if (this->Passing == false && this->callReturn == false && this->variables[j].GetValue(currentVariable, CurrentScope) != "false")
				{
					return j;
				}
				else if (this->Passing == true && this->callReturn == false && this->variables[j].GetValue(currentVariable, CurrentScope + 1) != "false")
				{
					return j;
				}
				else if (this->Passing == true && this->callReturn == true && this->variables[j].GetValue(currentVariable, CurrentScope) != "false")
				{
					return j;
				}
				else if (this->variables.size() - 1 == j)
				{
					if (this->Passing == false && this->callReturn == false)
					{
						this->variables.push_back(Variables(currentVariable, 0, CurrentScope));
						return j + 1;
					}
					else if (this->Passing == true && this->callReturn == false)
					{
						this->variables.push_back(Variables(currentVariable, 0, CurrentScope + 1));
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
				this->variables.push_back(Variables(currentVariable, 0, CurrentScope + 1));
				return 0;
			}
			else if (this->Passing == true && this->callReturn == true)
			{
				this->variables.push_back(Variables(currentVariable, 0, CurrentScope));
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

//Go down scope
void Scope::inecrmentScope() 
{
	this->CurrentScope++;
}

//Go up scope
void Scope::decrementScope()
{
	this->CurrentScope--;

}

//Return to call
void Scope::CallReturn(bool callReturn)
{
	this->callReturn = callReturn;
}

//Pass a parameter
void Scope::paramPassing(bool Passing)
{
	this->Passing = Passing;
}