#ifndef SCOPE
#define SCOPE
#include <vector>
#include <string>


class Scope {

private:
		int CurrentScope;
		bool Passing, inFunct;

public:
		Scope();
		void inecrmentScope();
		void decrementScope();


};