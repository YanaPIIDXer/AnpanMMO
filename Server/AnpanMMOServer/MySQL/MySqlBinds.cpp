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
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_LONG;
	Bind.buffer = pPtr;
	Bind.buffer_length = sizeof(*pPtr);
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// unsigned int�^�ǉ�.
void MySqlBinds::AddInt(unsigned int *pPtr)
{
	MYSQL_BIND Bind;
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_LONG;
	Bind.is_unsigned = true;
	Bind.buffer = pPtr;
	Bind.buffer_length = sizeof(*pPtr);
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// short�ǉ�.
void MySqlBinds::AddShort(short *pPtr)
{
	MYSQL_BIND Bind;
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_SHORT;
	Bind.buffer = pPtr;
	Bind.buffer_length = sizeof(*pPtr);
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// unsigned short�ǉ�.
void MySqlBinds::AddShort(unsigned short *pPtr)
{
	MYSQL_BIND Bind;
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_SHORT;
	Bind.buffer = pPtr;
	Bind.buffer_length = sizeof(*pPtr);
	Bind.is_unsigned = true;
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// char�ǉ�.
void MySqlBinds::AddChar(char *pPtr)
{
	MYSQL_BIND Bind;
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_TINY;
	Bind.buffer = pPtr;
	Bind.buffer_length = sizeof(*pPtr);
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// unsigned char�ǉ�.
void MySqlBinds::AddChar(unsigned char *pPtr)
{
	MYSQL_BIND Bind;
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_TINY;
	Bind.buffer = pPtr;
	Bind.buffer_length = sizeof(*pPtr);
	Bind.is_unsigned = true;
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// float�ǉ�.
void MySqlBinds::AddFloat(float *pPtr)
{
	MYSQL_BIND Bind;
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_FLOAT;
	Bind.buffer = pPtr;
	Bind.buffer_length = sizeof(*pPtr);
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}

// ������ǉ�.
void MySqlBinds::AddString(char *pPtr)
{
	MYSQL_BIND Bind;
	memset(&Bind, 0, sizeof(Bind));
	Bind.buffer_type = MYSQL_TYPE_STRING;
	Bind.buffer = pPtr;
	Bind.buffer_length = strlen(pPtr) + 1;
	Bind.is_null = 0;

	Reallocate();
	pBinds[Length - 1] = Bind;
}


// �̈�g��.
void MySqlBinds::Reallocate()
{
	MYSQL_BIND *pTmp = pBinds;
	Length++;
	pBinds = new MYSQL_BIND[Length];
	for (int i = 0; i < Length - 1; i++)
	{
		pBinds[i] = pTmp[i];
	}

	delete[] pTmp;
}
