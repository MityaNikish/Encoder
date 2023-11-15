#include "pch.h"
#include "Encoder.h"
#include "Exception.h"

#include "ElectronicCodebook.h"
#include "CipherBlockChaining.h"
#include "PropagationCipherBlockChaining.h"


TEST(Encryption, ElectronicCodebook_EmptyStr)
{
	std::string origNumber = "";

	Encoder User;
	User.setEncoder(std::make_unique<ElectronicCodebook>());

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, ElectronicCodebook_DefoultKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<ElectronicCodebook>());

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, ElectronicCodebook_SetKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<ElectronicCodebook>(25));

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, ElectronicCodebook_SetInvalidKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<ElectronicCodebook>(-1565498));

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, ElectronicCodebook_VariousKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;

	User.setEncoder(std::make_unique<ElectronicCodebook>(25));
	std::string resNumberEncr = User.useEncryption(origNumber);

	User.setEncoder(std::make_unique<ElectronicCodebook>(156));
	std::string resNumberDecr = User.useDecryption(resNumberEncr);

	EXPECT_NE(origNumber, resNumberDecr);
}



TEST(Encryption, CipherBlockChaining_EmptyStr)
{
	std::string origNumber = "";

	Encoder User;
	User.setEncoder(std::make_unique<CipherBlockChaining>());

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, CipherBlockChaining_DefoultKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<CipherBlockChaining>());

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, CipherBlockChaining_SetKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<CipherBlockChaining>(68, 68));

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, CipherBlockChaining_VariousKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;

	User.setEncoder(std::make_unique<CipherBlockChaining>(68, 68));
	std::string resNumberEncr = User.useEncryption(origNumber);

	User.setEncoder(std::make_unique<CipherBlockChaining>(8, 25));
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_NE(origNumber, resNumberDecr);
}



TEST(Encryption, PropagationCipherBlockChaining_EmptyStr)
{
	std::string origNumber = "";

	Encoder User;
	User.setEncoder(std::make_unique<PropagationCipherBlockChaining>());

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, PropagationCipherBlockChaining_DefoultKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<PropagationCipherBlockChaining>());

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, PropagationCipherBlockChaining_SetKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<PropagationCipherBlockChaining>(68, 68));
	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, PropagationCipherBlockChaining_VariousKey)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	User.setEncoder(std::make_unique<PropagationCipherBlockChaining>(68, 68));
	std::string resNumberEncr = User.useEncryption(origNumber);

	User.setEncoder(std::make_unique<PropagationCipherBlockChaining>(78, 37));
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_NE(origNumber, resNumberDecr);
}



TEST(Encryption, Default)
{
	std::string origNumber = "Hello World!!!";
	std::string resNumber;

	Encoder User;

	EXPECT_THROW({ resNumber = User.useEncryption(origNumber); }, not_selected_strategy);
	EXPECT_THROW({ resNumber = User.useDecryption(origNumber); }, not_selected_strategy);
}

TEST(Encryption, VariousEncoder)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;

	User.setEncoder(std::make_unique<ElectronicCodebook>(55));
	std::string resNumberEncr = User.useEncryption(origNumber);

	User.setEncoder(std::make_unique<CipherBlockChaining>(55, 55));
	std::string resNumberDecr = User.useDecryption(resNumberEncr);

	EXPECT_NE(origNumber, resNumberDecr);
}

TEST(Encryption, MultipleStrategies)
{
	std::string origNumber = "Hello World!!!";
	std::string resNumberEncr;
	std::string resNumberDecr;

	Encoder User;
	User.setEncoder(std::make_unique<ElectronicCodebook>(98));
	resNumberEncr = User.useEncryption(origNumber);
	resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);

	User.setEncoder(std::make_unique<CipherBlockChaining>(26, 68));
	resNumberEncr = User.useEncryption(origNumber);
	resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);

	User.setEncoder(std::make_unique<PropagationCipherBlockChaining>(32, 18));
	resNumberEncr = User.useEncryption(origNumber);
	resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(Encryption, Unvalidity)
{
	std::string origNumber = "Hello World!!!";
	std::string resNumberEncr;
	std::string resNumberDecr;

	Encoder User;
	Encoder UserEmty;
	User.setEncoder(std::make_unique<ElectronicCodebook>(98));
	User = std::move(UserEmty);

	EXPECT_THROW({ resNumberEncr = User.useEncryption(origNumber); }, not_selected_strategy);
	EXPECT_THROW({ resNumberDecr = User.useDecryption(resNumberEncr); }, not_selected_strategy);
}



TEST(Exeption, Test)
{
	std::string origNumber = "Hello World!!!";

	Encoder User;
	EXPECT_THROW(std::string resNumberEncr = User.useEncryption(origNumber), not_selected_strategy);
}

//TEST(EncriptuionMode, Test1)
//{
//	std::string origNumber = "Hi";
//	std::string resNumber;
//
//	EncryptionMode* mode;
//	//resNumberEncr = mode->encryption(origNumber);
//	//origNumber = mode->decryption(resNumberEncr);
//
//	ElectronicCodebook A;
//	mode = &A;
//
//	resNumber = mode->encryption(origNumber);
//	origNumber = mode->decryption(resNumber);
//
//	CipherBlockChaining B;
//	mode = &B;
//
//	resNumber = mode->encryption(origNumber);
//	origNumber = mode->decryption(resNumber);
//}