#include "stdafx.h"
#include "DBConnection.h"
#include <fstream>

const std::string DBConnection::UserDataFileName = "DBUserData.txt";
const char *DBConnection::DBHost = "127.0.0.1";
const char *DBConnection::DBName = "AnpanMMO";
DBConnection DBConnection::Instance;

// 開く
bool DBConnection::Open()
{
	std::ifstream FileStream(UserDataFileName);
	if (!FileStream)
	{
		std::cout << UserDataFileName << " Open Failed..." << std::endl;
		return false;
	}

	char UserName[256];
	char PassWord[256];
	FileStream.getline(UserName, 256);
	FileStream.getline(PassWord, 256);
	FileStream.close();

	return Connection.Connect(DBHost, UserName, PassWord, DBName);
}

// ユーザデータ読み込み
bool DBConnection::LoadUserData(char *pUserName, char *pPassWord)
{
	MySqlQuery Query = Connection.CreateQuery("select Id from UserData where UserName = ? and PassWord = ?");
	Query.BindString(pUserName);
	Query.BindString(pPassWord);

	int Id = 0;
	Query.BindResultInt(&Id);
	if (!Query.ExecuteQuery()) { return false; }

	if (!Query.Fetch()) { return false; }
	
	return true;
}

// ユーザデータ登録.
bool DBConnection::RegisterUserData(char *pUserName, char *pPassWord)
{
	// ユーザ名重複チェック
	MySqlQuery CheckQuery = Connection.CreateQuery("select UserName from UserData where UserName = ?");
	CheckQuery.BindString(pUserName);
	CheckQuery.ExecuteQuery();
	if (CheckQuery.Fetch()) { return false; }
	
	// 登録.
	MySqlQuery Query = Connection.CreateQuery("insert into UserData Values(?, ?)");
	Query.BindString(pUserName);
	Query.BindString(pPassWord);
	if (!Query.ExecuteQuery()) { return false; }

	return true;
}
