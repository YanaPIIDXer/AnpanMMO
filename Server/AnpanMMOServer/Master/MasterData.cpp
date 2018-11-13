#include "stdafx.h"
#include "MasterData.h"
#include <fstream>
#include "MySQL/MySqlConnection.h"
#include "Test2Master.h"
#include "Test3Master.h"

const char *MasterData::DBHost = "127.0.0.1";
const char *MasterData::DBName = "AnpanMMOMaster";
const std::string MasterData::DBDataFileName = "MasterDBUserData.txt";
MasterData MasterData::Instance;

// 読み込み
bool MasterData::Read()
{
	std::ifstream FileStream(DBDataFileName.c_str());
	if (!FileStream)
	{
		std::cout << DBDataFileName << " Open Failed..." << std::endl;
		return false;
	}

	char UserName[128];
	char Password[128];
	FileStream.getline(UserName, 128);
	FileStream.getline(Password, 128);
	FileStream.close();

	MySqlConnection Connection;
	if (!Connection.Connect(DBHost, UserName, Password, DBName))
	{
		std::cout << "Master Database Connection Failed..." << std::endl;
		return false;
	}
	
	// テスト２
	Test2Master Test2;
	if (!Test2.Load(Connection)) { return false; }

	std::vector<Test2Item> Test2Items = Test2.GetAll();
	std::cout << "Test2Master DataCount:" << Test2Items.size() << std::endl;
	for (std::vector<Test2Item>::iterator It = Test2Items.begin(); It != Test2Items.end(); ++It)
	{
		std::cout << "ID:" << It->ID << " Hp:" << It->Hp << " Mp:" << It->Mp << " Exp:" << It->Exp << std::endl;
	}

	// テスト３
	Test3Master Test3;
	if (!Test3.Load(Connection)) { return false; }

	std::vector<Test3Item> Test3Items = Test3.GetAll();
	std::cout << std::endl << "Test3Master DataCount:" << Test2Items.size() << std::endl;
	for (std::vector<Test3Item>::iterator It = Test3Items.begin(); It != Test3Items.end(); ++It)
	{
		std::cout << "ID:" << It->ID << " Hp:" << It->Hp << " Mp:" << It->Mp << " Exp:" << It->Exp << std::endl;
	}

	return true;
}
