#ifndef SCOPE
#define SCOPE
#include <vector>
#include <string>
#include "Variables.h"


class Scope {

private:
	std::vector<Variables>variables;
		int CurrentScope;
		bool Passing, callReturn;

public:
		Scope();
		void inecrmentScope();
		void decrementScope();
		int GetAddress(std::string currentVariable);
		void CallReturn(bool callRetyrb);
		void paramPassing(bool Passing);
		int GetValue(std::string i);
		void SetValue(int varAddress, int value);
};
#endif