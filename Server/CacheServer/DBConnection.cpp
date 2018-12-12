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

// キャラクタデータが存在するか？
bool DBConnection::IsExistCharacter(int Id, bool &OutResult)
{
	MySqlQuery Query = Connection.CreateQuery("select CustomerId from CharacterData where CustomerId = ?");
	Query.BindInt(&Id);

	int DummyId;
	Query.BindResultInt(&DummyId);

	if (!Query.ExecuteQuery()) { return false; }
	OutResult = Query.Fetch();
	
	return true;
}

// キャラクタデータ登録.
bool DBConnection::RegisterCharacterData(u32 Id, char *pCharacterName, u8 Job)
{
	MySqlQuery Query = Connection.CreateQuery("insert into CharacterData values(?, ?, ?, 1, 50, 10, 10, 0, 0, 1, -1000.0, 0.0, 0.0);");
	Query.BindInt(&Id);
	Query.BindString(pCharacterName);
	Query.BindChar(&Job);
	if (!Query.ExecuteQuery()) { return false; }
	return true;
}

// キャラクタパラメータ読み込み
bool DBConnection::LoadCharacterParameter(int Id, std::string &OutName, u8 &OutJob, u32 &OutLevel, int &OutMaxHp, int &OutAtk, int &OutDef, int &OutExp, u32 &OutGold)
{
	MySqlQuery Query = Connection.CreateQuery("select Name, Job, Level, MaxHp, Atk, Def, Exp Gold from CharacterData where CustomerId = ?");
	Query.BindInt(&Id);

	char NameStr[256];
	
	Query.BindResultString(NameStr);
	Query.BindResultChar(&OutJob);
	Query.BindResultInt(&OutLevel);
	Query.BindResultInt(&OutMaxHp);
	Query.BindResultInt(&OutAtk);
	Query.BindResultInt(&OutDef);
	Query.BindResultInt(&OutExp);
	Query.BindResultInt(&OutGold);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	OutName = NameStr;
	return true;
}

// キャラクタパラメータ書き込み
bool DBConnection::SaveCharacterParameter(int Id, u32 Level, int MaxHp, int Atk, int Def, int Exp, int AreaId, float X, float Y, float Z)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set Level = ?, MaxHp = ?, Atk = ?, Def = ?, Exp = ?, LastArea = ?, LastX = ?, LastY = ?, LastZ = ? where CustomerId = ?");

	Query.BindInt(&Level);
	Query.BindInt(&MaxHp);
	Query.BindInt(&Atk);
	Query.BindInt(&Def);
	Query.BindInt(&Exp);
	Query.BindInt(&AreaId);
	Query.BindFloat(&X);
	Query.BindFloat(&Y);
	Query.BindFloat(&Z);
	Query.BindInt(&Id);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// ゴールド書き込み
bool DBConnection::SaveGold(int Id, u32 Gold)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set Gold = ? where CustomerId = ?");

	Query.BindInt(&Gold);
	Query.BindInt(&Id);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// 最後にログアウトした位置を読み込み
bool DBConnection::ReadLastLogoutPosition(int Id, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ)
{
	MySqlQuery Query = Connection.CreateQuery("select LastArea, LastX, LastY, LastZ from CharacterData where CustomerId = ?");

	Query.BindInt(&Id);
	Query.BindResultInt(&OutAreaId);
	Query.BindResultFloat(&OutX);
	Query.BindResultFloat(&OutY);
	Query.BindResultFloat(&OutZ);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// スクリプトフラグをロード
bool DBConnection::LoadScriptFlags(int Id, u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3)
{
	MySqlQuery Query = Connection.CreateQuery("select BitField1, BitField2, BitField3 from ScriptFlags where CustomerId = ?");
	
	Query.BindInt(&Id);

	Query.BindResultInt(&OutBitField1);
	Query.BindResultInt(&OutBitField2);
	Query.BindResultInt(&OutBitField3);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch())
	{
		// 新規登録.
		MySqlQuery InsertQuery = Connection.CreateQuery("insert into ScriptFlags values(?, 0, 0, 0);");

		InsertQuery.BindInt(&Id);
		if (InsertQuery.ExecuteQuery()) { return false; }
		OutBitField1 = 0;
		OutBitField2 = 0;
		OutBitField3 = 0;
	}
	return true;
}

// スクリプトフラグを保存.
bool DBConnection::SaveScriptFlags(int Id, u32 BitField1, u32 BitField2, u32 BitField3)
{
	MySqlQuery Query = Connection.CreateQuery("update ScriptFlags set BitField1 = ?, BitField2 = ?, BitField3 = ? where CustomerId = ?");

	Query.BindInt(&BitField1);
	Query.BindInt(&BitField2);
	Query.BindInt(&BitField3);
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

	return true;
}
