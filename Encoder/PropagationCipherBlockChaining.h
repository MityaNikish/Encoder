#pragma once
#include "EncryptionMode.h"

class PropagationCipherBlockChaining final : public EncryptionMode
{
	uint8_t def_init_vector_ = 255;

public:
	PropagationCipherBlockChaining() = default;
	PropagationCipherBlockChaining(uint8_t key, uint8_t def_init_vector);
	~PropagationCipherBlockChaining() override = default;
	PropagationCipherBlockChaining& operator=(const PropagationCipherBlockChaining&) = delete;
	PropagationCipherBlockChaining(const PropagationCipherBlockChaining&) = delete;

private:
	[[nodiscard]] std::string encryption(const std::string& str) const override;
	[[nodiscard]] std::string decryption(const std::string& str) const override;

private:
	unsigned char algorithm(unsigned char ch) const;
};