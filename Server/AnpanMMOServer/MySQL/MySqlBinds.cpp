#include "stdafx.h"
#include "MySqlBinds.h"

// �R���X�g���N�^
MySqlBinds::MySqlBinds()
	: pBinds(NULL)
	, Length(0)
{
}

// �f�X�g���N�^
MySqlBinds::~MySqlBinds()
{
	delete[] pBinds;
	pBinds = NULL;
}

// int�ǉ�.
void MySqlBinds::AddInt(int *pPtr)
{
	MYSQL_BIND Bind;
	Bind.buffer_type = MYSQL_TYPE_LONG;
	Bind.buffer = pPtr;
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// ������ǉ�.
void MySqlBinds::AddString(char *pPtr)
{
	MYSQL_BIND Bind;
	Bind.buffer_type = MYSQL_TYPE_STRING;
	Bind.buffer = pPtr;
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}


// �̈�g��.
void MySqlBinds::Reallocate()
{
	delete[] pBinds;

	Length++;
	pBinds = new MYSQL_BIND[Length];
}
