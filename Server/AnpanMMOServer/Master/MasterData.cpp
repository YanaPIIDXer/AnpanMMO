#include "stdafx.h"
#include "MasterData.h"
#include <fstream>
#include "MySQL/MySqlConnection.h"
#include "TestMaster.h"

const char *MasterData::DBHost = "127.0.0.1";
const char *MasterData::DBName = "AnpanMMOMaster";
const std::string MasterData::DBDataFileName = "MasterDBUserData.txt";
MasterData MasterData::Instance;

// �ǂݍ���
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

	// �e�X�g
	TestMaster Test;
	Test.Load(Connection);

	std::vector<TestItem> TestItems = Test.GetAll();
	std::cout << "TestItem Count:" << TestItems.size() << std::endl;
	for (std::vector<TestItem>::iterator It = TestItems.begin(); It != TestItems.end(); ++It)
	{
		std::cout << "ID:" << It->ID << " Name:" << It->Name << std::endl;
	}
	
	return true;
}
