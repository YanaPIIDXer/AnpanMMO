#include "stdafx.h"
#include "MySqlQuery.h"

// �R���X�g���N�^
MySqlQuery::MySqlQuery(MYSQL *pInConnection, const char *pInQuery)
	: pConnection(pInConnection)
	, pQuery(pInQuery)
	, pStatement(NULL)
{
}

// �f�X�g���N�^
MySqlQuery::~MySqlQuery()
{
	Close();
}

// int�^�̃o�C���h
void MySqlQuery::BindInt(int *pPtr)
{
	Binds.AddInt(pPtr);
}

// unsigned int�^�̃o�C���h
void MySqlQuery::BindInt(unsigned int *pPtr)
{
	Binds.AddInt(pPtr);
}

// short�^�̃o�C���h
void MySqlQuery::BindShort(short *pPtr)
{
	Binds.AddShort(pPtr);
}

// unsigned short�^�̃o�C���h
void MySqlQuery::BindShort(unsigned short *pPtr)
{
	Binds.AddShort(pPtr);
}

// char�^�̃o�C���h
void MySqlQuery::BindChar(char *pPtr)
{
	Binds.AddChar(pPtr);
}

// unsigned char�^�̃o�C���h
void MySqlQuery::BindChar(unsigned char *pPtr)
{
	Binds.AddChar(pPtr);
}

// float�^�̃o�C���h
void MySqlQuery::BindFloat(float *pPtr)
{
	Binds.AddFloat(pPtr);
}

// ������̃o�C���h
void MySqlQuery::BindString(char *pPtr)
{
	Binds.AddString(pPtr, false);
}

// ���C�h������̃o�C���h
void MySqlQuery::BindWString(wchar_t *pPtr)
{
	Binds.AddWString(pPtr, false);
}

// ���ʂ�int�^�o�C���h
void MySqlQuery::BindResultInt(int *pPtr)
{
	Results.AddInt(pPtr);
}

// ���ʂ�unsigned int�^�̃o�C���h
void MySqlQuery::BindResultInt(unsigned int *pPtr)
{
	Results.AddInt(pPtr);
}

// ���ʂ�short�^�̃o�C���h
void MySqlQuery::BindResultShort(short *pPtr)
{
	Results.AddShort(pPtr);
}

// ���ʂ�unsigned short�^�̃o�C���h
void MySqlQuery::BindResultShort(unsigned short *pPtr)
{
	Results.AddShort(pPtr);
}

// ���ʂ�char�^�o�C���h
void MySqlQuery::BindResultChar(char *pPtr)
{
	Results.AddChar(pPtr);
}

// ���ʂ�unsigned char�^�o�C���h
void MySqlQuery::BindResultChar(unsigned char *pPtr)
{
	Results.AddChar(pPtr);
}

// ���ʂ�float�^�o�C���h
void MySqlQuery::BindResultFloat(float *pPtr)
{
	Results.AddFloat(pPtr);
}

// ���ʂ̕�����o�C���h
void MySqlQuery::BindResultString(char *pPtr)
{
	Results.AddString(pPtr, true);
}

// ���ʂ̃��C�h������o�C���h
void MySqlQuery::BindResultWString(wchar_t *pPtr)
{
	Results.AddWString(pPtr, true);
}

// �N�G�����s.
bool MySqlQuery::ExecuteQuery()
{
	pStatement = mysql_stmt_init(pConnection);
	if (pStatement == NULL) { return false; }
	
	int Result = mysql_stmt_prepare(pStatement, pQuery, strlen(pQuery));
	if (Result != 0)
	{
		std::cout << "Prepare Error:" << mysql_stmt_error(pStatement) << std::endl;
		return false;
	}

	MYSQL_BIND *pBinds = Binds.Get();
	if (pBinds != NULL)
	{
		Result = mysql_stmt_bind_param(pStatement, pBinds);
		if (Result != 0)
		{
			std::cout << "Bind Param Error:" << mysql_stmt_error(pStatement) << std::endl;
			return false;
		}
	}

	MYSQL_BIND *pResults = Results.Get();
	if (pResults != NULL)
	{
		Result = mysql_stmt_bind_result(pStatement, pResults);
		if (Result != 0)
		{
			std::cout << "Bind Result Error:" << mysql_stmt_error(pStatement) << std::endl;
			return false;
		}
	}

	Result = mysql_stmt_execute(pStatement);
	if (Result != 0)
	{
		std::cout << "Execute Error:" << mysql_stmt_error(pStatement) << std::endl;
		return false;
	}

	return true;
}

// �t�F�b�`
bool MySqlQuery::Fetch()
{
	if (pStatement == NULL) { return false; }

	int Result = mysql_stmt_fetch(pStatement);
	if (Result == 1)
	{
		std::cout << "Fetch Error:" << mysql_stmt_error(pStatement) << std::endl;
	}
	return (Result == 0 || Result == MYSQL_DATA_TRUNCATED);
}

// ����
void MySqlQuery::Close()
{
	if (pStatement == NULL) { return; }

	mysql_stmt_close(pStatement);
	pStatement = NULL;
}
