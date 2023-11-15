#pragma once
#include <string>

class EncryptionMode
{
public:
	virtual std::string encryption(const std::string& str) = 0;
	virtual std::string decryption(const std::string& str) = 0;
};