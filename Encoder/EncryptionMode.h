#pragma once
#include <string>

class EncryptionMode
{
	friend class Encoder;
public:
	virtual ~EncryptionMode() = default;

protected:
	uint8_t key_ = 255;

	virtual std::string encryption(const std::string& str) const = 0;
	virtual std::string decryption(const std::string& str) const = 0;
};