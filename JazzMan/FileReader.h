#ifndef FILEREADER
#define FILEREADER
#include <vector>
#include "Parsing.h"
class FileReader 
{
public:
	FileReader(std::string FileName, std::vector<Parsing> &placeholder);
};
#endif