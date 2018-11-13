
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

	// unsigned int�^�̃o�C���h
	void BindInt(unsigned int *pPtr);

	// short�^�̃o�C���h
	void BindShort(short *pPtr);

	// unsigned short�^�̃o�C���h
	void BindShort(unsigned short *pPtr);

	// char�^�̃o�C���h
	void BindChar(char *pPtr);

	// unsigned char�^�̃o�C���h
	void BindChar(unsigned char *pPtr);

	// float�^�̃o�C���h
	void BindFloat(float *pPtr);

	// ������̃o�C���h
	void BindString(char *pPtr);

	// ���ʂ�int�^�o�C���h
	void BindResultInt(int *pPtr);

	// ���ʂ�unsigned int�^�̃o�C���h
	void BindResultInt(unsigned int *pPtr);

	// ���ʂ�short�^�̃o�C���h
	void BindResultShort(short *pPtr);

	// ���ʂ�unsigned short�^�̃o�C���h
	void BindResultShort(unsigned short *pPtr);

	// ���ʂ�char�^�̃o�C���h
	void BindResultChar(char *pPtr);

	// ���ʂ�unsigned char�^�̃o�C���h
	void BindResultChar(unsigned char *pPtr);

	// ���ʂ�float�^�o�C���h
	void BindResultFloat(float *pPtr);

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
