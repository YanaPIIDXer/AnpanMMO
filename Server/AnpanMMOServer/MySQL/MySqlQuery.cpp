#include "stdafx.h"
#include "MySqlQuery.h"

// コンストラクタ
MySqlQuery::MySqlQuery(MYSQL *pInConnection, const char *pInQuery)
	: pConnection(pInConnection)
	, pQuery(pInQuery)
	, pStatement(NULL)
{
}

// デストラクタ
MySqlQuery::~MySqlQuery()
{
	Close();
}

// int型のバインド
void MySqlQuery::BindInt(int *pPtr)
{
	Binds.AddInt(pPtr);
}

// unsigned int型のバインド
void MySqlQuery::BindInt(unsigned int *pPtr)
{
	Binds.AddInt(pPtr);
}

// short型のバインド
void MySqlQuery::BindShort(short *pPtr)
{
	Binds.AddShort(pPtr);
}

// unsigned short型のバインド
void MySqlQuery::BindShort(unsigned short *pPtr)
{
	Binds.AddShort(pPtr);
}

// char型のバインド
void MySqlQuery::BindChar(char *pPtr)
{
	Binds.AddChar(pPtr);
}

// unsigned char型のバインド
void MySqlQuery::BindChar(unsigned char *pPtr)
{
	Binds.AddChar(pPtr);
}

// float型のバインド
void MySqlQuery::BindFloat(float *pPtr)
{
	Binds.AddFloat(pPtr);
}

// 文字列のバインド
void MySqlQuery::BindString(char *pPtr)
{
	Binds.AddString(pPtr, false);
}

// ワイド文字列のバインド
void MySqlQuery::BindWString(wchar_t *pPtr)
{
	Binds.AddWString(pPtr, false);
}

// 結果のint型バインド
void MySqlQuery::BindResultInt(int *pPtr)
{
	Results.AddInt(pPtr);
}

// 結果のunsigned int型のバインド
void MySqlQuery::BindResultInt(unsigned int *pPtr)
{
	Results.AddInt(pPtr);
}

// 結果のshort型のバインド
void MySqlQuery::BindResultShort(short *pPtr)
{
	Results.AddShort(pPtr);
}

// 結果のunsigned short型のバインド
void MySqlQuery::BindResultShort(unsigned short *pPtr)
{
	Results.AddShort(pPtr);
}

// 結果のchar型バインド
void MySqlQuery::BindResultChar(char *pPtr)
{
	Results.AddChar(pPtr);
}

// 結果のunsigned char型バインド
void MySqlQuery::BindResultChar(unsigned char *pPtr)
{
	Results.AddChar(pPtr);
}

// 結果のfloat型バインド
void MySqlQuery::BindResultFloat(float *pPtr)
{
	Results.AddFloat(pPtr);
}

// 結果の文字列バインド
void MySqlQuery::BindResultString(char *pPtr)
{
	Results.AddString(pPtr, true);
}

// 結果のワイド文字列バインド
void MySqlQuery::BindResultWString(wchar_t *pPtr)
{
	Results.AddWString(pPtr, true);
}

// クエリ実行.
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

// フェッチ
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

// 閉じる
void MySqlQuery::Close()
{
	if (pStatement == NULL) { return; }

	mysql_stmt_close(pStatement);
	pStatement = NULL;
}
