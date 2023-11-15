#include "PropagationCipherBlockChaining.h"


PropagationCipherBlockChaining::PropagationCipherBlockChaining(uint8_t key, uint8_t def_init_vector)
{
	key_ = key;
	def_init_vector_ = def_init_vector;
};

std::string PropagationCipherBlockChaining::encryption(const std::string& str) const
{
	std::string new_str;
	uint8_t init_vector = def_init_vector_;

	for (const char _char : str)
	{
		init_vector = algorithm(static_cast<char>(_char ^ init_vector));
		new_str.push_back(static_cast<char>(init_vector));
		init_vector = init_vector ^ _char;
	}

	return new_str;
}

std::string PropagationCipherBlockChaining::decryption(const std::string& str) const
{
	std::string new_str;
	if (str.empty())
	{
		return new_str;
	}
	unsigned char init_vector = algorithm(str[0]);

	new_str.push_back(static_cast<char>(def_init_vector_ ^ init_vector));

	for (int j = 0; j < str.length() - 1; j++)
	{
		init_vector = algorithm(str[j + 1]) ^ new_str[j];
		new_str.push_back(static_cast<char>(str[j] ^ init_vector));
	}

	return new_str;
}

unsigned char PropagationCipherBlockChaining::algorithm(unsigned char ch) const
{
	return ch ^ key_;
}