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

	// �L�����N�^�f�[�^�����݂��邩�H
	bool IsExistCharacter(int Id, bool &OutResult);

	// �L�����N�^�f�[�^�o�^.
	bool RegisterCharacterData(u32 Id, char *pCharacterName);

	// �L�����N�^�p�����[�^�ǂݍ���
	bool LoadCharacterParameter(int Id, std::string &OutName, int &OutMaxHp, int &OutAtk, int &OutDef, int &OutExp);

	// �L�����N�^�p�����[�^��������
	bool SaveCharacterParameter(int Id, int MaxHp, int Atk, int Def, int Exp, int AreaId, float X, float Y, float Z);

	// �Ō�Ƀ��O�A�E�g�����ʒu��ǂݍ���
	bool ReadLastLogoutPosition(int Id, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ);

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
