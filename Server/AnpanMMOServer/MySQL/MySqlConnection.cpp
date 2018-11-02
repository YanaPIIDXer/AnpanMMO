#include "stdafx.h"
#include "MySqlConnection.h"

// コンストラクタ
MySqlConnection::MySqlConnection()
	: pConnection(NULL)
{
}

// デストラクタ
MySqlConnection::~MySqlConnection()
{
	Close();
}

// 接続.
bool MySqlConnection::Connect(const char *pHost, const char *pUserName, const char *pPassword, const char *pDBName)
{
	if (pConnection != NULL)
	{
		Close();
	}

	MYSQL *pConn = mysql_init(NULL);
	if (pConn == NULL) { return false; }

	if (!mysql_real_connect(pConn, pHost, pUserName, pPassword, pDBName, 0, NULL, 0)) { return false; }

	pConnection = shared_ptr<MYSQL>(pConn);
	return true;
}

// 閉じる
void MySqlConnection::Close()
{
	if (pConnection == NULL) { return; }

	mysql_close(pConnection.get());
	pConnection = NULL;
}
