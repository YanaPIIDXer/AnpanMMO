#include "stdafx.h"
#include "WordChecker.h"
#include "MySQL/MySqlConnection.h"
#include <fstream>

const std::string WordChecker::MasterDBInfoFileName = "MasterDBUserData.txt";
WordChecker WordChecker::Instance;

// チャット用ワードチェック
std::string WordChecker::ChatWordCheck(const std::string &Message)
{
	std::string Result = Message;

	std::wcout.imbue(std::locale(""));
	std::vector<NGWordItem> WordList = NGWords.GetAll();
	for (unsigned int i = 0; i < WordList.size(); i++)
	{
		// @TODO;愚直な判定。
		//		 全角半角を考慮する方法ってある・・・？
		std::string NGWord = WordList[i].NGWord;
		std::cout << NGWord << std::endl;
		size_t Pos = Result.find(NGWord);
		if (Pos == std::string::npos) { continue; }
		size_t Length = NGWord.length();
		std::string Replace = "";
		for (size_t j = 0; j < Length; j++)
		{
			Replace += "*";
		}
		Result = Result.replace(Pos, Length, Replace);
	}

	return Result;
}

// マスタの読み込み
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

	std::vector<NGWordItem> WordList = NGWords.GetAll();
	for (unsigned int i = 0; i < WordList.size(); i++)
	{
		std::cout << "NGWord:" << WordList[i].NGWord << std::endl;
	}

	std::cout << "WordChecker LoadMaster Success!!" << std::endl;
	return true;
}
