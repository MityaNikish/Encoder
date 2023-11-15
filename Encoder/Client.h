#pragma once
#include "Encoder.h"

#include "ElectronicCodebook.h"
#include "CipherBlockChaining.h"

class Client : public Encoder
{
public:
	void setEncoder(EncryptionMode& strg);
	std::string useEncryption(const std::string& str);
	std::string useDecryption(const std::string& str);
};