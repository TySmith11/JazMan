#ifndef fuckyou
#define SYMBOLS
#include <string>
#include <vector>
#include "Parsing.h"
#include "Scope.h"
#include "Stack.h"
#include "FileReader.h"

class Symbols
{
private:
	Stack stack;
	Scope scoping;
	std::vector<Parsing> placeholder;
	void doLogic(int i);

public:
	Readit(std::string FileName);
	int Whatdo(int position);
	

};
#endif