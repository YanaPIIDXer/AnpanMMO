#include "stdafx.h"
#include "MySqlBinds.h"

// コンストラクタ
MySqlBinds::MySqlBinds()
	: pBinds(NULL)
	, Length(0)
{
}

// デストラクタ
MySqlBinds::~MySqlBinds()
{
	delete[] pBinds;
	pBinds = NULL;
}

// int追加.
void MySqlBinds::AddInt(int *pPtr)
{
	MYSQL_BIND Bind;
	Bind.buffer_type = MYSQL_TYPE_LONG;
	Bind.buffer = pPtr;
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// 文字列追加.
void MySqlBinds::AddString(char *pPtr)
{
	MYSQL_BIND Bind;
	Bind.buffer_type = MYSQL_TYPE_STRING;
	Bind.buffer = pPtr;
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}


// 領域拡張.
void MySqlBinds::Reallocate()
{
	delete[] pBinds;

	Length++;
	pBinds = new MYSQL_BIND[Length];
}
