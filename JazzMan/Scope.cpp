#include <iostream>
#include "Scope.h"
using namespace std;

Scope::Scope()
{
	this->CurrentScope = 0;
	this->inFunct = true;
	this->Passing = false;


}
