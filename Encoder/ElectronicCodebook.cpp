#include "ElectronicCodebook.h"


ElectronicCodebook::ElectronicCodebook(uint8_t key)
{
	key_ = key;
};

std::string ElectronicCodebook::encryption(const std::string& str) const
{
	std::string new_str;
	for (const auto _char : str)
	{
		new_str.push_back(static_cast<char>(_char ^ key_));
	}

	return new_str;
}

std::string ElectronicCodebook::decryption(const std::string& str) const
{
	return encryption(str);
}