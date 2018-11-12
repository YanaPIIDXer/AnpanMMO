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

	// float�ǉ�.
	void AddFloat(float *pPtr);

	// ������ǉ�.
	void AddString(char *pPtr);

	// �擾.
	MYSQL_BIND *Get() { return pBinds; }

private:

	// �o�C���h
	MYSQL_BIND *pBinds;

	// �z��.
	int Length;

	// �̈�g��.
	void Reallocate();

};

#endif		// #ifndef __MYSQLBINDS_H__

