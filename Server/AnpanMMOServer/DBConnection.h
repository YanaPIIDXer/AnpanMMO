#ifndef __DBCONNECTION_H__
#define __DBCONNECTION_H__

#include "MySQL/MySqlConnection.h"

/**
 * DB�ڑ��N���X
 */
class DBConnection : noncopyable
{

public:

	// �J��.
	bool Open();

	// ���[�U�f�[�^�ǂݍ���
	bool LoadUserData(char *pUserName, char *pPassWord, int &OutId);

private:

	// ���[�U�����i�[�����t�@�C����.
	static const std::string UserDataFileName;

	// DB�̃z�X�g
	static const char *DBHost;

	// �f�[�^�x�[�X��.
	static const char *DBName;

	// �ڑ�.
	MySqlConnection Connection;

	// ======== Singleton ===========
public:

	static DBConnection &GetInstance() { return Instance; }

private:

	DBConnection() {}
	static DBConnection Instance;

};

#endif		// #ifndef __DBCONNECTION_H__
