#include "stdafx.h"
#include "WordChecker.h"
#include "MySQL/MySqlConnection.h"
#include <fstream>
#include <algorithm>

const std::string WordChecker::MasterDBInfoFileName = "MasterDBUserData.txt";
WordChecker WordChecker::Instance;

// チャット用ワードチェック
std::string WordChecker::ChatWordCheck(const std::string &Message)
{
	std::string Result = Message;

	std::vector<NGWordItem> WordList = NGWords.GetAll();
	for (unsigned int i = 0; i < WordList.size(); i++)
	{
		// @TODO;愚直な判定。
		//		 全角半角を考慮する方法ってある・・・？
		std::string NGWord = WordList[i].NGWord;
		std::string Tmp1 = Result;
		std::string Tmp2 = NGWord;
		std::transform(Tmp1.begin(), Tmp1.end(), Tmp1.begin(), toupper);
		std::transform(Tmp2.begin(), Tmp2.end(), Tmp2.begin(), toupper);
		size_t Pos = Tmp1.find(Tmp2);
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

	std::cout << "WordChecker LoadMaster Success!!" << std::endl;
	return true;
}
