/**
 * @file PlayerCharacter.h
 * @brief �v���C���[�L�����N�^�N���X
 * @author YanaP
 */
#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "Character/CharacterBase.h"
#include "PlayerExp.h"
#include "Skill/SkillTree/SkillTree.h"
#include "WeakPtrDefine.h"
#include "Packet/CharacterType.h"
#include "Item/ItemList.h"
#include "Equip/EquipData.h"

class Client;
class ItemData;

/**
 * @class PlayerCharacter
 * @brief �v���C���[�L�����N�^
 */
class PlayerCharacter : public CharacterBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInClient �N���C�A���g
	 * @param[in] InCharacterId �L�����N�^�h�c
	 * @param[in] InJob �W���u
	 * @param[in] Level ���x��
	 * @param[in] InExp �o���l
	 * @param[in] InGold �S�[���h
	 * @oaran[in] RightEquipId �E�葕���h�c
	 * @param[in] LeftEquipId ���葕���h�c
	 */
	PlayerCharacter(Client *pInClient, u32 InCharacterId, u8 InJob, u32 Level, u32 InExp, u32 InGold, u32 RightEquipId, u32 LeftEquipId);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~PlayerCharacter();

	/**
	 * @fn Client *GetClient() const
	 * @brief �N���C�A���g�擾
	 * @return �N���C�A���g
	 */
	Client *GetClient() const { return pClient; }

	/**
	 * @fn void AddExp(int Value)
	 * @brief �o���l����
	 * @param[in] Value ������
	 */
	void AddExp(int Value) { Exp.Add(Value); }

	/**
	 * @fn int GetExp() const
	 * @brief �o���l�擾
	 * @return �o���l
	 */
	int GetExp() const { return Exp.Get(); }

	/**
	 * @fn void SetName(const std::string &InName)
	 * @brief ���O��ݒ�
	 * @param[in] InName ���O
	 */
	void SetName(const std::string &InName) { Name = InName; }

	/**
	 * @fn const std::string &GetName() const
	 * @brief ���O���擾
	 * @return ���O
	 */
	const std::string &GetName() const { return Name; }

	/**
	 * @fn u32 GetCharacterId() const
	 * @brief �L�����N�^�h�c�擾
	 * @return �L�����N�^�h�c
	 */
	u32 GetCharacterId() const { return CharacterId; }

	/**
	 * @fn u8 GetJob() const
	 * @brief �W���u���擾
	 * @return �W���u
	 */
	u8 GetJob() const { return Job; }

	/**
	 * @fn virtual u8 GetCharacterType() const
	 * @brief �L�����N�^�^�C�v���擾
	 * @return �L�����N�^�^�C�v
	 */
	virtual u8 GetCharacterType() const { return CharacterType::Player; }

	/**
	 * @fn void SetParty(const PartyPtr &pInParty)
	 * @brief �p�[�e�B��ݒ�
	 * @param[in] pInParty �p�[�e�B�ւ�weak_ptr
	 */
	void SetParty(const PartyPtr &pInParty) { pParty = pInParty; }

	/**
	 * @fn PartyPtr GetParty() const
	 * @brief �p�[�e�B���擾
	 * @return �p�[�e�B�ւ�weak_ptr
	 */
	PartyPtr GetParty() const { return pParty; }

	/**
	 * @fn void OnMoved()
	 * @brief �ړ�����
	 */
	void OnMoved();

	/**
	 * @fn void OnAreaChange()
	 * @brief �G���A���؂�ւ����
	 */
	void OnAreaChange();

	/**
	 * @fn 832 GetGold() const
	 * @brief �S�[���h���擾
	 * @return �S�[���h
	 */
	u32 GetGold() const { return Gold; }

	/**
	 * @fn void AddGold(u32 Value)
	 * @brief �S�[���h�𑝉�
	 * @param[in] Value ������
	 */
	void AddGold(u32 Value);

	/**
	 * @fn void SubtractGold(u32 Value)
	 * @brief �S�[���h������
	 * @param[in] Value �����
	 */
	void SubtractGold(u32 Value);

	/**
	 * @fn void InitializeSkillTree(const FlexArray<u32> &OpenedNodes)
	 * @brief �X�L���c���[������
	 * @param[in] OpenedNodes �J���Ă���m�[�h
	 */
	void InitializeSkillTree(const FlexArray<u32> &OpenedNodes);

	/**
	 * @fn const SkillTree &GetSkillTree() const
	 * @brief �X�L���c���[�擾
	 * @return �X�L���c���[
	 */
	const SkillTree &GetSkillTree() const { return Tree; }

	/**
	 * @fn u8 OpenSkillTree(u32 NodeId)
	 * @brief �X�L���c���[�̃m�[�h���J��
	 * @param[in] NodeId �m�[�h�h�c
	 * @return ���U���g�R�[�h
	 */
	u8 OpenSkillTree(u32 NodeId);

	/**
	 * @fn void OnRecvItemList(const FlexArray<ItemData> &List)
	 * @brief �A�C�e�����X�g����M����
	 * @param[in] List �A�C�e�����X�g
	 */
	void OnRecvItemList(const FlexArray<ItemData> &List);

	/**
	 * @fn void UseItem(u32 ItemId, CharacterPtr pTarget)
	 * @brief �A�C�e���g�p
	 * @param[in] ItemId �A�C�e���h�c
	 * @param[in] pTarget �^�[�Q�b�g�ւ�weak_ptr
	 */
	void UseItem(u32 ItemId, CharacterPtr pTarget);

	/**
	 * @fn void AddItem(u32 ItemId, u32 Count)
	 * @brief �A�C�e������
	 * @param[in] ItemId �A�C�e���h�c
	 * param[in] Count ��
	 */
	void AddItem(u32 ItemId, u32 Count);

	/**
	 * @fn void SubtractItem(u32 ItemId, u32 Count)
	 * @brief �A�C�e������
	 * @param[in] ItemId �A�C�e���h�c
	 * @param[in] Count ��
	 */
	void SubtractItem(u32 ItemId, u32 Count);

	/**
	 * @fn const ItemList &GetItemList() const
	 * @brief �A�C�e�����X�g�擾
	 * @return �A�C�e�����X�g
	 */
	const ItemList &GetItemList() const { return Items; }

	/**
	 * @fn void ChangeEquip(u32 RightEquipId, u32 LeftEquipId)
	 * @brief �����؂�ւ�
	 * @param[in] RightEquipId �E�葕���h�c
	 * @param[in] LeftEquipId ���葕���h�c
	 */
	void ChangeEquip(u32 RightEquipId, u32 LeftEquipId);

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

	// �E�葕��.
	EquipData RightEquip;

	// ���葕��.
	EquipData LeftEquip;

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

	// �E�Q�����B
	void OnKilled(CharacterBase *pKilledCharacter);

	// �h���b�v�A�C�e�����擾�B
	void GetDrop(u32 DropId);

};

#endif		// #ifndef __PLAYERCHARACTER_H__
