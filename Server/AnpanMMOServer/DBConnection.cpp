#include "stdafx.h"
#include "DBConnection.h"
#include <fstream>

const std::string DBConnection::UserDataFileName = "DBUserData.txt";
const char *DBConnection::DBHost = "127.0.0.1";
const char *DBConnection::DBName = "AnpanMMO";
DBConnection DBConnection::Instance;

// �J��
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

// ���[�U�f�[�^�ǂݍ���
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

// ���[�U�f�[�^�o�^.
bool DBConnection::RegisterUserData(char *pUserName, char *pPassWord)
{
	// ���[�U���d���`�F�b�N
	MySqlQuery CheckQuery = Connection.CreateQuery("select UserName from UserData where UserName = ?");
	CheckQuery.BindString(pUserName);
	CheckQuery.ExecuteQuery();
	if (CheckQuery.Fetch()) { return false; }
	
	// �o�^.
	MySqlQuery Query = Connection.CreateQuery("insert into UserData Values(?, ?)");
	Query.BindString(pUserName);
	Query.BindString(pPassWord);
	if (!Query.ExecuteQuery()) { return false; }

	return true;
}
