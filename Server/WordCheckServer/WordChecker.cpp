#include "stdafx.h"
#include "WordChecker.h"
#include "MySQL/MySqlConnection.h"
#include <fstream>

const std::string WordChecker::MasterDBInfoFileName = "MasterDBUserData.txt";
WordChecker WordChecker::Instance;

// É}ÉXÉ^ÇÃì«Ç›çûÇ›
bool WordChecker::LoadMaster()
{
	std::ifstream FileStream(MasterDBInfoFileName.c_str());
	if (!FileStream)
	{
		std::cout << MasterDBInfoFileName << " Load Failed..." << std::endl;
		return false;
	}
	char UserName[256];
	char Password[256];
	FileStream.getline(UserName, 256);
	FileStream.getline(Password, 256);

	MySqlConnection Connection;
	if (!Connection.Connect("127.0.0.1", UserName, Password, "AnpanMMOMaster"))
	{
		std::cout << "Master DB Connection Failed..." << std::endl;
		return false;
	}

	if (!NGWords.Load(Connection))
	{
		std::cout << "NGWord Master Load Failed..." << std::endl;
		return false;
	}

	std::cout << "WordChecker LoadMaster Success!!" << std::endl;
	return true;
}
