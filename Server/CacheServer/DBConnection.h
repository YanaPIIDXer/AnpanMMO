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

	// �X�N���v�g�t���O�����[�h
	bool LoadScriptFlags(int Id, u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3);

	// �X�N���v�g�t���O��ۑ�.
	bool SaveScriptFlags(int Id, u32 BitField1, u32 BitField2, u32 BitField3);

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
