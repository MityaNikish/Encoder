#pragma once
#include "EncryptionMode.h"

class ElectronicCodebook final : public EncryptionMode
{
public:
	ElectronicCodebook() = default;
	ElectronicCodebook(uint8_t key);
	~ElectronicCodebook() override = default;
	ElectronicCodebook& operator=(const ElectronicCodebook&) = delete;
	ElectronicCodebook(const ElectronicCodebook&) = delete;

private:
	[[nodiscard]] std::string encryption(const std::string& str) const override;
	[[nodiscard]] std::string decryption(const std::string& str) const override;
};