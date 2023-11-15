#include "Parser.h"
#include "Exception.h"

std::string read_file(const char* file_name)
{
	std::ifstream fin(file_name, std::ios_base::in);
	if (fin.is_open())
	{
		return  { std::istreambuf_iterator(fin), std::istreambuf_iterator<char>() };
	}
	throw opening_file_exception();
}
