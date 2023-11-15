#include "Encoder.h"
#include "Exception.h"

void Encoder::setEncoder(std::unique_ptr<const EncryptionMode> strg)
{
	mode = std::move(strg);
}

std::string Encoder::useEncryption(const std::string& str) const
{
	if (mode)
	{
		return mode->encryption(str);
	}
	throw not_selected_strategy();
}

std::string Encoder::useDecryption(const std::string& str) const
{
	if (mode)
	{
		return mode->decryption(str);
	}
	throw not_selected_strategy();
}