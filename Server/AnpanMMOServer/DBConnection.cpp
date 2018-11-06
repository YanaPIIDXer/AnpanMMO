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
	std::ifstream FileStream(UserDataFileName.c_str());
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
bool DBConnection::LoadUserData(char *pUserCode, int &OutId)
{
	MySqlQuery Query = Connection.CreateQuery("select Id from UserData where UserCode = ?;");
	Query.BindString(pUserCode);

	int Id = 0;
	Query.BindResultInt(&Id);
	if (!Query.ExecuteQuery()) { return false; }

	if (!Query.Fetch())
	{
		// 登録して検索し直す。
		if (!RegisterUserData(pUserCode)) { return false; }
		return LoadUserData(pUserCode, OutId);
	}
	
	OutId = Id;
	return true;
}

// キャラクタパラメータ読み込み
bool DBConnection::LoadCharacterParameter(int Id, int &OutMaxHp, int &OutAtk, int &OutDef, int &OutExp)
{
	MySqlQuery Query = Connection.CreateQuery("select MaxHp, Atk, Def, Exp from CharacterData where CustomerId = ?");
	Query.BindInt(&Id);

	Query.BindResultInt(&OutMaxHp);
	Query.BindResultInt(&OutAtk);
	Query.BindResultInt(&OutDef);
	Query.BindResultInt(&OutExp);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// キャラクタパラメータ書き込み
bool DBConnection::SaveCharacterParameter(int Id, int MaxHp, int Atk, int Def, int Exp)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set MaxHp = ?, Atk = ?, Def = ?, Exp = ? where CustomerId = ?");

	Query.BindInt(&MaxHp);
	Query.BindInt(&Atk);
	Query.BindInt(&Def);
	Query.BindInt(&Exp);
	Query.BindInt(&Id);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}


// ユーザデータ登録.
bool DBConnection::RegisterUserData(char *pUserCode)
{
	// ユーザデータ
	MySqlQuery Query = Connection.CreateQuery("insert into UserData(UserCode) Values(?)");
	Query.BindString(pUserCode);
	if (!Query.ExecuteQuery()) { return false; }
	Query.Close();

	// キャラデータ
	MySqlQuery UserQuery = Connection.CreateQuery("select Id from UserData where UserCode = ?;");
	UserQuery.BindString(pUserCode);

	int Id = 0;
	UserQuery.BindResultInt(&Id);
	if (!UserQuery.ExecuteQuery()) { return false; }
	if (!UserQuery.Fetch()) { return false; }
	UserQuery.Close();

	MySqlQuery CharacterQuery = Connection.CreateQuery("insert into CharacterData values(?, 50, 10, 10, 0);");
	CharacterQuery.BindInt(&Id);
	if (!CharacterQuery.ExecuteQuery()) { return false; }

	return true;
}
