#pragma once
#include "EncryptionMode.h"

class Encoder
{
public:
	virtual void setEncoder(EncryptionMode& strg) = 0;
	virtual std::string useEncryption(const std::string& str) = 0;
	virtual std::string useDecryption(const std::string& str) = 0;

protected:
	EncryptionMode* mode{};
};
