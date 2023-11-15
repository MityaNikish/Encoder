#include "pch.h"
#include "Client.h"
#include "Parser.h"
#include "Exception.h"

#include <fstream>

//#include <cstdlib>


//void main()
//{
//	std::string ffin = "file_in.txt";
//	std::string ffout = "file_out.txt";
//
//	std::string origNumber = read_file(ffin.c_str());
//
//
//	Client User;
//	ElectronicCodebook A;
//	CipherBlockChaining B;
//
//	User.setEncoder(A);
//	//User.setEncoder(B);
//
//	std::string resNumber = User.useEncryption(origNumber);
//
//	//std::string resNumber = User.useDecryption(origNumber);
//
//
//	//вывод
//	std::ofstream fout(ffout.c_str());
//	if (fout.is_open())
//	{
//		fout << resNumber;
//	}
//	fout.close();
//}


TEST(TestCaseEncryption, ElectronicCodebook_DefoultKey)
{
	std::string origNumber = "Hellow World!!!";

	Client User;
	ElectronicCodebook A;

	User.setEncoder(A);

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(TestCaseEncryption, ElectronicCodebook_SetKey)
{
	std::string origNumber = "Hellow World!!!";

	Client User;
	ElectronicCodebook A(25);

	User.setEncoder(A);

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(TestCaseEncryption, ElectronicCodebook_VariousKey)
{
	std::string origNumber = "Hellow World!!!";

	Client User;
	ElectronicCodebook A(25);
	ElectronicCodebook AA(156);

	User.setEncoder(A);
	std::string resNumberEncr = User.useEncryption(origNumber);

	User.setEncoder(AA);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);

	EXPECT_NE(origNumber, resNumberDecr);
}

TEST(TestCaseEncryption, CipherBlockChaining_DefoultKey)
{
	std::string origNumber = "Hellow World!!!";

	Client User;
	CipherBlockChaining B;

	User.setEncoder(B);

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(TestCaseEncryption, CipherBlockChaining_SetKey)
{
	std::string origNumber = "Hellow World!!!";

	Client User;
	CipherBlockChaining B(68);

	User.setEncoder(B);

	std::string resNumberEncr = User.useEncryption(origNumber);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);
	EXPECT_EQ(origNumber, resNumberDecr);
}

TEST(TestCaseEncryption, Defoult)
{
	std::string origNumber = "Hellow World!!!";
	std::string resNumber;

	Client User;

	EXPECT_THROW({ resNumber = User.useEncryption(origNumber); }, not_selected_strategy);

	EXPECT_THROW({ resNumber = User.useDecryption(origNumber); }, not_selected_strategy);
}

TEST(TestCaseEncryption, VariousEncoder)
{
	std::string origNumber = "Hellow World!!!";

	Client User;
	ElectronicCodebook A(55);
	CipherBlockChaining B(55);

	User.setEncoder(A);
	std::string resNumberEncr = User.useEncryption(origNumber);

	User.setEncoder(B);
	std::string resNumberDecr = User.useDecryption(resNumberEncr);

	EXPECT_NE(origNumber, resNumberDecr);
}

TEST(TestCaseExeption, Test1)
{
	std::string ffin = "file_WHEN_NO.txt";
	std::string origNumber;
	EXPECT_THROW({ origNumber = read_file(ffin.c_str()); }, opening_file_exception);
}