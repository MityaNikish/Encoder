#include "CipherBlockChaining.h"

CipherBlockChaining::CipherBlockChaining(unsigned char _key): key(_key) {};

std::string CipherBlockChaining::encryption(const std::string& str)
{
	std::string new_str;
	unsigned char init_vector = def_init_vector;

	for (int j = 0; j < str.length(); j++)
	{
		init_vector = algorithm(str[j] ^ init_vector);
		new_str.push_back(init_vector);
	}

	return new_str;
}

std::string CipherBlockChaining::decryption(const std::string& str)
{
	std::string new_str;
	unsigned char init_vector = algorithm(str[0]);

	new_str.push_back(def_init_vector ^ init_vector);

	for (int j = 0; j < str.length() - 1; j++)
	{
		init_vector = algorithm(str[j+1]);
		new_str.push_back(str[j] ^ init_vector);
	}

	return new_str;
}

unsigned char CipherBlockChaining::algorithm(unsigned char ch)
{
	return ch ^ key;
}