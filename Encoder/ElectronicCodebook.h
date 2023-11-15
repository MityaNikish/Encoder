#pragma once
#include "EncryptionMode.h"

class ElectronicCodebook : public EncryptionMode
{
	unsigned char key = 255;

public:
	ElectronicCodebook() = default;
	ElectronicCodebook(unsigned char _key);

	std::string encryption(const std::string& str) override;
	std::string decryption(const std::string& str) override;
};