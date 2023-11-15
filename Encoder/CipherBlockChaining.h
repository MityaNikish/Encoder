#pragma once
#include "EncryptionMode.h"

class CipherBlockChaining final : public EncryptionMode
{
	uint8_t def_init_vector_ = 255;

public:
	CipherBlockChaining() = default;
	CipherBlockChaining(uint8_t key, uint8_t def_init_vector);
	~CipherBlockChaining() override = default;
	CipherBlockChaining& operator=(const CipherBlockChaining&) = delete;
	CipherBlockChaining(const CipherBlockChaining&) = delete;

private:
	[[nodiscard]] std::string encryption(const std::string& str) const override;
	[[nodiscard]] std::string decryption(const std::string& str) const override;

private:
	unsigned char algorithm(unsigned char ch) const;
};