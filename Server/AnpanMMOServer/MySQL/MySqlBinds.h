#ifndef __MYSQLBINDS_H__
#define __MYSQLBINDS_H__

#ifdef _WIN32
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include <vector>

/**
 * �o�C���h
 */
class MySqlBinds
{

public:

	// �R���X�g���N�^
	MySqlBinds();

	// �f�X�g���N�^
	~MySqlBinds();

	// int�ǉ�.
	void AddInt(int *pPtr);

	// unsigned int�ǉ��B
	void AddInt(unsigned int *pPtr);

	// short�ǉ�.
	void AddShort(short *pPtr);

	// unsigned short�ǉ�.
	void AddShort(unsigned short *pPtr);

	// char�ǉ�.
	void AddChar(char *pPtr);

	// unsigned char�ǉ�.
	void AddChar(unsigned char *pPtr);

	// float�ǉ�.
	void AddFloat(float *pPtr);

	// ������ǉ�.
	void AddString(char *pPtr, bool bForResult);

	// ���C�h������ǉ�.
	void AddWString(wchar_t *pPtr, bool bForResult);

	// �擾.
	MYSQL_BIND *Get() { return pBinds; }

private:

	// String�^�̃o�b�t�@��.
	static const int StringBufferLength;

	// �o�C���h
	MYSQL_BIND *pBinds;

	// �z��.
	int Length;

	// �̈�g��.
	void Reallocate();

};

#endif		// #ifndef __MYSQLBINDS_H__

