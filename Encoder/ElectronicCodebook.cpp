#include "ElectronicCodebook.h"

ElectronicCodebook::ElectronicCodebook(unsigned char _key) : key(_key) {};

std::string ElectronicCodebook::encryption(const std::string& str)
{
	std::string new_str;
	for (int j = 0; j < str.length(); j++)
	{
		new_str.push_back(str[j] ^ key);
	}

	return new_str;
}

std::string ElectronicCodebook::decryption(const std::string& str)
{
	return encryption(str);
}