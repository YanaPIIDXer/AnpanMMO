#include "stdafx.h"
#include "MySqlConnection.h"

// �R���X�g���N�^
MySqlConnection::MySqlConnection()
	: pConnection(NULL)
{
}

// �f�X�g���N�^
MySqlConnection::~MySqlConnection()
{
	Close();
}

// �ڑ�.
bool MySqlConnection::Connect(const char *pHost, const char *pUserName, const char *pPassword, const char *pDBName)
{
	if (pConnection != NULL)
	{
		Close();
	}

	pConnection = mysql_init(NULL);
	if (pConnection == NULL) { return false; }

	if (!mysql_real_connect(pConnection, pHost, pUserName, pPassword, pDBName, 0, NULL, 0)) { return false; }
	return true;
}

// ����
void MySqlConnection::Close()
{
	if (pConnection == NULL) { return; }
	mysql_close(pConnection);
	pConnection = NULL;
}
