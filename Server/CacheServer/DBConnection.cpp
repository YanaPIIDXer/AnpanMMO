#include "stdafx.h"
#include "DBConnection.h"
#include <fstream>
#include "Packet/CharacterJob.h"
#include "Packet/ItemData.h"

const std::string DBConnection::UserDataFileName = "DBUserData.txt";
const char *DBConnection::DBHost = "127.0.0.1";
const char *DBConnection::DBName = "AnpanMMO";
DBConnection DBConnection::Instance;

// �J��
bool DBConnection::Open()
{
	std::ifstream FileStream(UserDataFileName.c_str());
	if (!FileStream)
	{
		std::cout << UserDataFileName << " Open Failed..." << std::endl;
		return false;
	}

	char UserName[256];
	char PassWord[256];
	FileStream.getline(UserName, 256);
	FileStream.getline(PassWord, 256);
	FileStream.close();

	return Connection.Connect(DBHost, UserName, PassWord, DBName);
}

// ���[�U�f�[�^�ǂݍ���
bool DBConnection::LoadUserData(char *pUserCode, int &OutId)
{
	MySqlQuery Query = Connection.CreateQuery("select Id from UserData where UserCode = ?;");
	Query.BindString(pUserCode);

	int Id = 0;
	Query.BindResultInt(&Id);
	if (!Query.ExecuteQuery()) { return false; }

	if (!Query.Fetch())
	{
		// �o�^���Č����������B
		if (!RegisterUserData(pUserCode)) { return false; }
		return LoadUserData(pUserCode, OutId);
	}
	
	OutId = Id;
	return true;
}

// �L�����N�^�f�[�^�����݂��邩�H
bool DBConnection::IsExistCharacter(int Id, bool &OutResult)
{
	MySqlQuery Query = Connection.CreateQuery("select CustomerId from CharacterData where CustomerId = ?");
	Query.BindInt(&Id);

	int DummyId;
	Query.BindResultInt(&DummyId);

	if (!Query.ExecuteQuery()) { return false; }
	OutResult = Query.Fetch();
	
	return true;
}

// �L�����N�^�h�c���擾.
bool DBConnection::GetCharacterId(int Id, u32 &OutCharacterId)
{
	MySqlQuery Query = Connection.CreateQuery("select CharacterId from CharacterData where CustomerId = ?");

	Query.BindInt(&Id);
	Query.BindResultInt(&OutCharacterId);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// �L�����N�^�f�[�^�o�^.
bool DBConnection::RegisterCharacterData(u32 Id, char *pCharacterName, u8 Job)
{
	MySqlQuery Query = Connection.CreateQuery("insert into CharacterData(CustomerId, Name, Job, Level, MaxHp, Atk, Def, Exp, Gold, LastArea, LastX, LastY, LastZ) values(?, ?, ?, 1, 50, 10, 10, 0, 0, 1, -1300.0, 4050.0, 42.0);");
	Query.BindInt(&Id);
	Query.BindString(pCharacterName);
	Query.BindChar(&Job);
	if (!Query.ExecuteQuery()) { return false; }
	Query.Close();

	// �X�L���e�[�u��
	// �܂��̓L�����N�^�h�c����������B
	u32 CharacterId = 0;
	Query = Connection.CreateQuery("select CharacterId from CharacterData where CustomerId = ?;");
	Query.BindInt(&Id);
	Query.BindResultInt(&CharacterId);
	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }
	Query.Close();

	// �e�[�u������.
	u32 NormalAttackId = 0;
	switch (Job)
	{
		case CharacterJob::Fighter:

			NormalAttackId = 1;
			break;

		case CharacterJob::Sorcerer:

			NormalAttackId = 6;
			break;

		case CharacterJob::Healer:

			NormalAttackId = 10;
			break;

		case CharacterJob::Lancer:

			NormalAttackId = 14;
			break;
	}

	Query = Connection.CreateQuery("insert into SkillData Values(?, ?, 0, 0, 0, 0);");
	Query.BindInt(&CharacterId);
	Query.BindInt(&NormalAttackId);
	if (!Query.ExecuteQuery()) { return false; }
	
	return true;
}

// �L�����N�^�p�����[�^�ǂݍ���
bool DBConnection::LoadCharacterParameter(int Id, u32 &OutCharacterId, std::string &OutName, u8 &OutJob, u32 &OutLevel, int &OutMaxHp, int &OutAtk, int &OutDef, int &OutExp, u32 &OutGold)
{
	MySqlQuery Query = Connection.CreateQuery("select CharacterId, Name, Job, Level, MaxHp, Atk, Def, Exp, Gold from CharacterData where CustomerId = ?");
	Query.BindInt(&Id);

	char NameStr[256];
	
	Query.BindResultInt(&OutCharacterId);
	Query.BindResultString(NameStr);
	Query.BindResultChar(&OutJob);
	Query.BindResultInt(&OutLevel);
	Query.BindResultInt(&OutMaxHp);
	Query.BindResultInt(&OutAtk);
	Query.BindResultInt(&OutDef);
	Query.BindResultInt(&OutExp);
	Query.BindResultInt(&OutGold);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	OutName = NameStr;
	return true;
}

// �L�����N�^�p�����[�^��������
bool DBConnection::SaveCharacterParameter(u32 CharacterId, u32 Level, int MaxHp, int Atk, int Def, int Exp, int AreaId, float X, float Y, float Z)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set Level = ?, MaxHp = ?, Atk = ?, Def = ?, Exp = ?, LastArea = ?, LastX = ?, LastY = ?, LastZ = ? where CharacterId = ?");

	Query.BindInt(&Level);
	Query.BindInt(&MaxHp);
	Query.BindInt(&Atk);
	Query.BindInt(&Def);
	Query.BindInt(&Exp);
	Query.BindInt(&AreaId);
	Query.BindFloat(&X);
	Query.BindFloat(&Y);
	Query.BindFloat(&Z);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// �X�L�����X�g�ǂݍ���
bool DBConnection::LoadSkillList(u32 CharacterId, u32 &OutNormalAttackId, u32 &OutSkill1, u32 &OutSkill2, u32 &OutSkill3, u32 &OutSkill4)
{
	MySqlQuery Query = Connection.CreateQuery("select NormalAttackId, Skill1, Skill2, Skill3, Skill4 from SkillData where CharacterId = ?;");
	Query.BindInt(&CharacterId);
	Query.BindResultInt(&OutNormalAttackId);
	Query.BindResultInt(&OutSkill1);
	Query.BindResultInt(&OutSkill2);
	Query.BindResultInt(&OutSkill3);
	Query.BindResultInt(&OutSkill4);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// �X�L�����X�g�ۑ�.
bool DBConnection::SaveSkillList(u32 CharacterId, u32 Skill1, u32 Skill2, u32 Skill3, u32 Skill4)
{
	MySqlQuery Query = Connection.CreateQuery("update SkillData set Skill1 = ?, Skill2 = ?, Skill3 = ?, Skill4 = ? where CharacterId = ?;");
	Query.BindInt(&Skill1);
	Query.BindInt(&Skill2);
	Query.BindInt(&Skill3);
	Query.BindInt(&Skill4);
	Query.BindInt(&CharacterId);
	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// �X�L���c���[�ǂݍ���
bool DBConnection::LoadSkillTree(u32 CharacterId, FlexArray<u32> &OutOpenedList)
{
	MySqlQuery Query = Connection.CreateQuery("select NodeId from SkillTree where CharacterId = ?;");
	Query.BindInt(&CharacterId);

	u32 NodeId;
	Query.BindResultInt(&NodeId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		OutOpenedList.PushBack(NodeId);
	}

	return true;
}

// �X�L���c���[�ۑ�.
bool DBConnection::SaveSkillTree(u32 CharacterId, u32 NodeId)
{
	MySqlQuery Query = Connection.CreateQuery("insert into SkillTree Values(?, ?);");
	Query.BindInt(&CharacterId);
	Query.BindInt(&NodeId);

	if (!Query.ExecuteQuery()) { return false; }
	return true;
}

// �A�C�e�����X�g�ǂݍ���
bool DBConnection::LoadItemList(u32 CharacterId, FlexArray<ItemData> &OutItemList)
{
	MySqlQuery Query = Connection.CreateQuery("select ItemId, Count from ItemData where CharacterId = ?");

	Query.BindInt(&CharacterId);

	ItemData BindData;
	Query.BindResultInt(&BindData.ItemId);
	Query.BindResultInt(&BindData.Count);
	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		OutItemList.PushBack(BindData);
	}

	return true;
}

// �A�C�e�����ω�.
bool DBConnection::ChangeItemCount(u32 CharacterId, u32 ItemId, u32 Count)
{
	// �܂��͊��Ƀ��X�g�ɑ��݂��邩�ǂ������`�F�b�N
	MySqlQuery Query = Connection.CreateQuery("select ItemId from ItemData where CharacterId = ? and ItemId = ?;");

	Query.BindInt(&CharacterId);
	Query.BindInt(&ItemId);

	u32 Dummy = 0;
	Query.BindResultInt(&Dummy);
	if (!Query.ExecuteQuery()) { return false; }
	if (Query.Fetch())
	{
		// ���݂���̂�update
		Query.Close();
		if (Count > 0)
		{
			Query = Connection.CreateQuery("update ItemData set Count = ? where CharacterId = ? and ItemId = ?;");

			Query.BindInt(&Count);
			Query.BindInt(&CharacterId);
			Query.BindInt(&ItemId);

			if (!Query.ExecuteQuery()) { return false; }
		}
		else
		{
			// �O�Ȃ�e�[�u������폜�B
			Query = Connection.CreateQuery("delete from ItemData where CharacterId = ? and ItemId = ?;");
			Query.BindInt(&CharacterId);
			Query.BindInt(&ItemId);

			if (!Query.ExecuteQuery()) { return false; }
		}
	}
	else
	{
		// ���݂��Ȃ��̂�insert
		Query.Close();
		if (Count == 0) { return true; }	// �O�Ȃ牽�����Ȃ��B
		Query = Connection.CreateQuery("insert into ItemData values(?, ?, ?);");
		Query.BindInt(&CharacterId);
		Query.BindInt(&ItemId);
		Query.BindInt(&Count);

		if (!Query.ExecuteQuery()) { return false; }
	}

	return true;
}

// �S�[���h��������
bool DBConnection::SaveGold(u32 CharacterId, u32 Gold)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set Gold = ? where CharacterId = ?");

	Query.BindInt(&Gold);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// �Ō�Ƀ��O�A�E�g�����ʒu��ǂݍ���
bool DBConnection::ReadLastLogoutPosition(u32 CharacterId, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ)
{
	MySqlQuery Query = Connection.CreateQuery("select LastArea, LastX, LastY, LastZ from CharacterData where CharacterId = ?");

	Query.BindInt(&CharacterId);
	Query.BindResultInt(&OutAreaId);
	Query.BindResultFloat(&OutX);
	Query.BindResultFloat(&OutY);
	Query.BindResultFloat(&OutZ);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// �X�N���v�g�t���O�����[�h
bool DBConnection::LoadScriptFlags(u32 CharacterId, u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3)
{
	MySqlQuery Query = Connection.CreateQuery("select BitField1, BitField2, BitField3 from ScriptFlags where CharacterId = ?");
	
	Query.BindInt(&CharacterId);

	Query.BindResultInt(&OutBitField1);
	Query.BindResultInt(&OutBitField2);
	Query.BindResultInt(&OutBitField3);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch())
	{
		// �V�K�o�^.
		MySqlQuery InsertQuery = Connection.CreateQuery("insert into ScriptFlags values(?, 0, 0, 0);");

		InsertQuery.BindInt(&CharacterId);
		if (InsertQuery.ExecuteQuery()) { return false; }
		OutBitField1 = 0;
		OutBitField2 = 0;
		OutBitField3 = 0;
	}
	return true;
}

// �X�N���v�g�t���O��ۑ�.
bool DBConnection::SaveScriptFlags(u32 CharacterId, u32 BitField1, u32 BitField2, u32 BitField3)
{
	MySqlQuery Query = Connection.CreateQuery("update ScriptFlags set BitField1 = ?, BitField2 = ?, BitField3 = ? where CharacterId = ?");

	Query.BindInt(&BitField1);
	Query.BindInt(&BitField2);
	Query.BindInt(&BitField3);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }
	return true;
}


// ���[�U�f�[�^�o�^.
bool DBConnection::RegisterUserData(char *pUserCode)
{
	// ���[�U�f�[�^
	MySqlQuery Query = Connection.CreateQuery("insert into UserData(UserCode) Values(?)");
	Query.BindString(pUserCode);
	if (!Query.ExecuteQuery()) { return false; }
	Query.Close();

	// �L�����f�[�^
	MySqlQuery UserQuery = Connection.CreateQuery("select Id from UserData where UserCode = ?;");
	UserQuery.BindString(pUserCode);

	int Id = 0;
	UserQuery.BindResultInt(&Id);
	if (!UserQuery.ExecuteQuery()) { return false; }
	if (!UserQuery.Fetch()) { return false; }
	UserQuery.Close();

	return true;
}
