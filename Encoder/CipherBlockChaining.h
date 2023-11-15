#pragma once
#include "EncryptionMode.h"
#include <random>

class CipherBlockChaining : public EncryptionMode
{
private:
	unsigned char key = 255;
	unsigned char def_init_vector = std::mt19937(std::random_device{}())() % 256;

public:
	CipherBlockChaining() = default;
	CipherBlockChaining(unsigned char _key);

public:
	std::string encryption(const std::string& str) override;
	std::string decryption(const std::string& str) override;

private:
	unsigned char algorithm(unsigned char ch);
};