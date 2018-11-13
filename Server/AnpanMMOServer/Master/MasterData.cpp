#include "stdafx.h"
#include "MasterData.h"
#include <fstream>
#include "MySQL/MySqlConnection.h"
#include "TestMaster.h"
#include "Test2Master.h"

const char *MasterData::DBHost = "127.0.0.1";
const char *MasterData::DBName = "AnpanMMOMaster";
const std::string MasterData::DBDataFileName = "MasterDBUserData.txt";
MasterData MasterData::Instance;

// ì«Ç›çûÇ›
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

	// ÉeÉXÉgÇP
	TestMaster Test;
	if (!Test.Load(Connection)) { return false; }
	
	std::vector<TestItem> TestItems = Test.GetAll();
	std::cout << "TestMaster DataCount:" << TestItems.size() << std::endl;
	for (std::vector<TestItem>::iterator It = TestItems.begin(); It != TestItems.end(); ++It)
	{
		std::cout << "ID:" << It->ID << " Name:" << It->Name << " Hp:" << It->Hp << " Mp:" << It->Mp << " Exp:" << It->Exp << std::endl;
	}

	Test2Master Test2;
	if (!Test2.Load(Connection)) { return false; }

	std::vector<Test2Item> Test2Items = Test2.GetAll();
	std::cout << std::endl << "Test2Master DataCount:" << Test2Items.size() << std::endl;
	for (std::vector<Test2Item>::iterator It = Test2Items.begin(); It != Test2Items.end(); ++It)
	{
		std::cout << "ID:" << It->ID << " Hp:" << It->Hp << " Mp:" << It->Mp << " Exp:" << It->Exp << std::endl;
	}

	return true;
}
