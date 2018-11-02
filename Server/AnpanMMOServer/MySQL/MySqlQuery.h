
#ifndef __MYSQLQUERY_H__
#define __MYSQLQUERY_H__

#ifdef _WIN32
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include "MySqlBinds.h"

/**
 * MySQL�N�G���N���X
 */
class MySqlQuery
{

public:

	// �R���X�g���N�^
	MySqlQuery(const shared_ptr<MYSQL> &pInConnection, const char *pInQuery);

	// �f�X�g���N�^
	~MySqlQuery();

	// int�^�̃o�C���h
	void BindInt(int *pPtr);

	// ������̃o�C���h
	void BindString(char *pPtr);

	// ���ʂ�int�^�o�C���h
	void BindResultInt(int *pPtr);

	// ���ʂ̕�����o�C���h
	void BindResultString(char *pPtr);

	// �N�G�����s.
	bool ExecuteQuery();

	// �t�F�b�`
	bool Fetch();

	// ����
	void Close();

private:

	// �N�G��
	const char *pQuery;

	// MYSQL�ւ̐ڑ�.
	weak_ptr<MYSQL> pConnection;

	// �X�e�[�g�����g
	MYSQL_STMT *pStatement;

	// �o�C���h
	MySqlBinds Binds;

	// ���ʃo�C���h
	MySqlBinds Results;

};

#endif		// #ifndef __MYSQLQUERY_H__
