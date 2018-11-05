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
	bool LoadUserData(char *pUserCode, int &OutId);

	// �L�����N�^�p�����[�^�ǂݍ���
	bool LoadCharacterParameter(int Id, int &OutMaxHp, int &OutAtk, int &OutDef, int &OutExp);

	// �L�����N�^�p�����[�^��������
	bool SaveCharacterParameter(int Id, int MaxHp, int Atk, int Def, int Exp);

private:

	// ���[�U�����i�[�����t�@�C����.
	static const std::string UserDataFileName;

	// DB�̃z�X�g
	static const char *DBHost;

	// �f�[�^�x�[�X��.
	static const char *DBName;

	// �ڑ�.
	MySqlConnection Connection;


	// ���[�U�f�[�^�o�^.
	bool RegisterUserData(char *pUserCode);

	// ======== Singleton ===========
public:

	static DBConnection &GetInstance() { return Instance; }

private:

	DBConnection() {}
	static DBConnection Instance;

};

#endif		// #ifndef __DBCONNECTION_H__
