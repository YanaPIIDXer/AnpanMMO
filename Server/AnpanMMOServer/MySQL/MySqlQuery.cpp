#include "stdafx.h"
#include "MySqlQuery.h"

// �R���X�g���N�^
MySqlQuery::MySqlQuery(const shared_ptr<MYSQL> &pInConnection)
	: pConnection(pInConnection)
	, pStatement(NULL)
{
}

// �f�X�g���N�^
MySqlQuery::~MySqlQuery()
{
}

// int�^�̃o�C���h
void MySqlQuery::BindInt(int *pPtr)
{
	Binds.AddInt(pPtr);
}

// ������̃o�C���h
void MySqlQuery::BindString(char *pPtr)
{
	Binds.AddString(pPtr);
}

// ���ʂ�int�^�o�C���h
void MySqlQuery::BindResultInt(int *pPtr)
{
	Results.AddInt(pPtr);
}

// ���ʂ̕�����o�C���h
void MySqlQuery::BindResultString(char *pPtr)
{
	Results.AddString(pPtr);
}

// �N�G�����s.
bool MySqlQuery::ExecuteQuery(const char *pQuery)
{
	pStatement = mysql_stmt_init(pConnection.lock().get());
	if (pStatement == NULL) { return false; }

	int Result = mysql_stmt_prepare(pStatement, pQuery, strlen(pQuery));
	if (Result != 0) { return false; }

	MYSQL_BIND *pBinds = Binds.Get();
	if (pBinds != NULL)
	{
		Result = mysql_stmt_bind_param(pStatement, pBinds);
		if (Result != 0) { return false; }
	}

	MYSQL_BIND *pResults = Results.Get();
	if (pResults != NULL)
	{
		Result = mysql_stmt_bind_result(pStatement, pResults);
		if (Result != 0) { return false; }
	}

	Result = mysql_stmt_execute(pStatement);
	if (Result != 0)
	{
		return false;
	}

	return true;
}

// �t�F�b�`
bool MySqlQuery::Fetch()
{
	if (pStatement == NULL) { return false; }

	int Result = mysql_stmt_fetch(pStatement);
	return (Result == 0);
}
