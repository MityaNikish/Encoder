#include "Parser.h"
#include "Exception.h"

std::string read_file(const char* file_name)
{
	std::ifstream fin(file_name, std::ios_base::in);
	if (fin.is_open())
	{
		return  { std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>() };
	}
	else
	{
		throw opening_file_exception();
	}
	fin.close();
}