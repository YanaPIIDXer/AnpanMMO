#ifndef __DBCONNECTION_H__
#define __DBCONNECTION_H__

#include "MySQL/MySqlConnection.h"
#include "FlexArray.h"

class ItemData;
class QuestData;

/**
 * DB�ڑ��N���X
 */
class DBConnection : noncopyable
{

public:

	// �J��.
	bool Open();

	// ���[�U�f�[�^�ǂݍ���
	bool LoadUserData(char *pUserCode, int &OutId, bool &bOutIsBunned);

	// �L�����N�^�f�[�^�����݂��邩�H
	bool IsExistCharacter(int Id, bool &OutResult);

	// �L�����N�^�h�c���擾.
	bool GetCharacterId(int Id, u32 &OutCharacterId);

	// �L�����N�^�f�[�^�o�^.
	bool RegisterCharacterData(u32 Id, char *pCharacterName, u8 Job);

	// �L�����N�^�p�����[�^�ǂݍ���
	bool LoadCharacterParameter(int Id, u32 &OutCharacterId, std::string &OutName, u8 &OutJob, u32 &OutLevel, u32 &OutExp, u32 &OutGold, bool &bOutIsGM, u32 &OutRightEquip, u32 &OutLeftEquip);

	// �L�����N�^�p�����[�^��������
	bool SaveCharacterParameter(u32 CharacterId, u32 Level, u32 Exp, int AreaId, float X, float Y, float Z);

	// �X�L�����X�g�ǂݍ���
	bool LoadSkillList(u32 CharacterId, u32 &OutSkill1, u32 &OutSkill2, u32 &OutSkill3, u32 &OutSkill4);

	// �X�L�����X�g�ۑ�.
	bool SaveSkillList(u32 CharacterId, u32 Skill1, u32 Skill2, u32 Skill3, u32 Skill4);

	// �X�L���c���[�ǂݍ���
	bool LoadSkillTree(u32 CharacterId, FlexArray<u32> &OutOpenedList);

	// �X�L���c���[�ۑ�.
	bool SaveSkillTree(u32 CharacterId, u32 NodeId);

	// �A�C�e�����X�g�ǂݍ���
	bool LoadItemList(u32 CharacterId, FlexArray<ItemData> &OutItemList);

	// �A�C�e�����ω�.
	bool ChangeItemCount(u32 CharacterId, u32 ItemId, u32 Count);

	// �A�C�e���V���[�g�J�b�g�ǂݍ��݁B
	bool LoadItemShortcut(u32 CharacterId, u32 &OutItemId1, u32 &OutItemId2);

	// �A�C�e���V���[�g�J�b�g�������݁B
	bool SaveItemShortcut(u32 CharacterId, u32 ItemId1, u32 ItemId2);

	// �S�[���h��������
	bool SaveGold(u32 CharacterId, u32 Gold);

	// �Ō�Ƀ��O�A�E�g�����ʒu��ǂݍ���
	bool ReadLastLogoutPosition(u32 CharacterId, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ);

	// �X�N���v�g�t���O�����[�h
	bool LoadScriptFlags(u32 CharacterId, u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3);

	// �X�N���v�g�t���O��ۑ�.
	bool SaveScriptFlags(u32 CharacterId, u32 BitField1, u32 BitField2, u32 BitField3);

	// �N�G�X�g�f�[�^�ǂݍ��݁B
	bool LoadQuestData(u32 CharacterId, FlexArray<QuestData> &OutDataList, u32 &OutActiveQuestId);

	// �N�G�X�g�f�[�^�ۑ�.
	bool SaveQuestData(u32 CharacterId, u32 QuestId, u32 StageNo, u32 KillCount, u8 State);

	// �A�N�e�B�u�N�G�X�g��ۑ�.
	bool SaveActiveQuest(u32 CharacterId, u32 QuestId);

	// �N�G�X�g�f�[�^�j��.
	bool EraseQuestData(u32 CharacterId, u32 QuestId);

	// �����f�[�^�ۑ�.
	bool SaveEquipData(u32 CharacterId, u32 RightEquip, u32 LeftEquip);

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
