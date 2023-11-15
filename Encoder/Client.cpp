#include "Client.h"
#include "Exception.h"

void Client::setEncoder(EncryptionMode& strg)
{
	mode = &strg;
}

std::string Client::useEncryption(const std::string& str)
{
	if (mode)
	{
		return mode->encryption(str);
	}
	throw not_selected_strategy();
}

std::string Client::useDecryption(const std::string& str)
{
	if (mode)
	{
		return mode->decryption(str);
	}
	throw not_selected_strategy();
}