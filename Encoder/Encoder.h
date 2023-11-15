#pragma once
#include <memory>
#include "EncryptionMode.h"

class Encoder final
{
public:
	void setEncoder(std::unique_ptr<const EncryptionMode> strg);
	[[nodiscard]] std::string useEncryption(const std::string& str) const;
	[[nodiscard]] std::string useDecryption(const std::string& str) const;

private:
	std::unique_ptr<const EncryptionMode> mode;
};
