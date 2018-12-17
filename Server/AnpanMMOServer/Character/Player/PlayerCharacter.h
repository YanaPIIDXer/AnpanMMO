#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "Character/CharacterBase.h"
#include "PlayerExp.h"
#include "Skill/SkillTree/SkillTree.h"
#include "WeakPtrDefine.h"
#include "Packet/CharacterType.h"
#include "Item/ItemList.h"

class Client;
class ItemData;

/**
 * �v���C���[�L�����N�^
 */
class PlayerCharacter : public CharacterBase
{

public:

	// �R���X�g���N�^
	PlayerCharacter(Client *pInClient, u32 InCharacterId, u8 InJob, u32 Level, int MaxHp, int Atk, int Def, int InExp, u32 InGold);

	// �f�X�g���N�^
	virtual ~PlayerCharacter();

	// �N���C�A���g�擾.
	Client *GetClient() const { return pClient; }

	// �o���l�ǉ�.
	void AddExp(int Value) { Exp.Add(Value); }

	// �o���l�擾.
	int GetExp() const { return Exp.Get(); }

	// ���O��ݒ�.
	void SetName(const std::string &InName) { Name = InName; }

	// �L�����N�^�h�c���擾.
	u32 GetCharacterId() const { return CharacterId; }

	// ���O���擾.
	const std::string &GetName() const { return Name; }

	// �W���u���擾.
	u8 GetJob() const { return Job; }

	// �L�����N�^�^�C�v���擾.
	virtual u8 GetCharacterType() const { return CharacterType::Player; }

	// �p�[�e�B��ݒ�.
	void SetParty(const PartyPtr &pInParty) { pParty = pInParty; }

	// �p�[�e�B���擾.
	PartyPtr GetParty() const { return pParty; }

	// �ړ������B
	void OnMoved();

	// �G���A���؂�ւ�����B
	void OnAreaChange();

	// �S�[���h�擾.
	u32 GetGold() const { return Gold; }

	// �S�[���h��ǉ�.
	void AddGold(u32 Value);

	// �S�[���h������.
	void SubtractGold(u32 Value);

	// �X�L���c���[������.
	void InitializeSkillTree(const FlexArray<u32> &OpenedNodes);

	// �X�L���c���[�擾.
	const SkillTree &GetSkillTree() const { return Tree; }

	// �X�L���c���[�I�[�v��
	u8 OpenSkillTree(u32 NodeId);

	// �A�C�e�����X�g����M�����B
	void OnRecvItemList(const FlexArray<ItemData> &List);

	// �A�C�e���g�p.
	void UseItem(u32 ItemId, CharacterPtr pTarget);

	// �A�C�e���j��.
	void SubtractItem(u32 ItemId, u32 Count);

private:

	// �N���C�A���g
	Client *pClient;

	// �o���l.
	PlayerExp Exp;

	// �L�����N�^�h�c
	u32 CharacterId;

	// ���O.
	std::string Name;

	// �W���u
	u8 Job;

	// �S�[���h
	u32 Gold;

	// �p�[�e�B
	PartyPtr pParty;

	// �X�L���c���[
	SkillTree Tree;

	// �A�C�e�����X�g
	ItemList Items;

	// �Z�[�u����G���A�h�c
	u32 SaveAreaId;

	// �Z�[�u������W.
	Vector3D SavePosition;


	// ���x���A�b�v�R�[���o�b�N
	void OnLevelUp();

	// �p�����[�^��ۑ�.
	void SaveParameter();

	// �X�L�����L�����Z�����ꂽ�B
	void OnSkillCanceled(u8 Reason);

	// ���L���X�g�����������B
	void OnSkillRecastFinished(u32 SkillId);

	// �A�C�e�����g�p�����B
	void OnUsedItem(u32 ItemId);

};

#endif		// #ifndef __PLAYERCHARACTER_H__
