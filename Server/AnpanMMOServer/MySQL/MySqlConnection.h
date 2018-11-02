#ifndef __MYSQLCONNECTION_H__
#define __MYSQLCONNECTION_H__

#ifdef _WIN32
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

/**
 * MySQL�ڑ��N���X
 */
class MySqlConnection
{

public:

	// �R���X�g���N�^
	MySqlConnection();

	// �f�X�g���N�^
	~MySqlConnection();

	// �ڑ�.
	bool Connect(const char *pHost, const char *pUserName, const char *pPassword, const char *pDBName);

	// ����.
	void Close();

private:

	// MySQL�ւ̐ڑ�.
	MYSQL *pConnection;

};

#endif		// #ifndef __MYSQLCONNECTION_H__
