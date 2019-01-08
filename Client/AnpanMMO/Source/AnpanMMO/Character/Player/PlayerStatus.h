// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Skill/SkillTree/SkillTree.h"
#include "Item/ItemList.h"

/**
 * �v���C���[�X�e�[�^�X
 */
class ANPANMMO_API PlayerStatus
{

public:

	// �R���X�g���N�^
	PlayerStatus();

	// �f�X�g���N�^
	~PlayerStatus() {}

	// Uuid�Z�b�g
	void SetUuid(uint32 InUuid) { Uuid = InUuid; }

	// �Z�b�g
	void Set(uint32 InLevel, int32 InMaxHp, int32 InStr, int32 InDef, int32 InInt, int32 InMnd, int32 InVit)
	{
		Level = InLevel;
		MaxHp = InMaxHp;
		Str = InStr;
		Def = InDef;
		Int = InInt;
		Mnd = InMnd;
		Vit = InVit;
	}

	// �o���l�Z�b�g
	void SetExp(int32 InExp) { Exp = InExp; }

	// ���O���Z�b�g
	void SetName(const FString &InName) { Name = InName; }

	// ���O���擾.
	const FString &GetName() const { return Name; }

	// Uuid�擾.
	uint32 GetUuid() const { return Uuid; }

	// �W���u���Z�b�g
	void SetJob(uint8 InJob)
	{
		Job = InJob;
		Tree.Initialize(Job);
	}

	// �W���u���擾.
	u8 GetJob() const { return Job; }

	// �S�[���h���Z�b�g
	void SetGold(uint32 InGold) { Gold = InGold; }

	// �S�[���h���擾.
	uint32 GetGold() const { return Gold; }

	// ���x�����擾.
	uint32 GetLevel() const { return Level; }

	// �ő�HP�擾.
	int32 GetMaxHp() const { return MaxHp; }

	// STR�擾.
	int32 GetStr() const { return Str; }

	// DEF�擾.
	int32 GetDef() const { return Def; }

	// INT�擾.
	int32 GetInt() const { return Int; }

	// MND�擾.
	int32 GetMnd() const { return Mnd; }

	// VIT�擾.
	int32 GetVit() const { return Vit; }

	// �o���l�擾.
	int32 GetExp() const { return Exp; }

	// �X�L�����X�g���Z�b�g�B
	void SetSkillList(uint32 NormalAttack, uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4);

	// �X�L�����X�g���擾.
	const TArray<uint32> &GetSkillList() const { return SkillList; }

	// �X�L���c���[�̃m�[�h���J���B
	void OpenSkillTreeNode(uint32 NodeId);

	// �X�L���c���[�̍č\�z.
	void RefleshSkillTree() { Tree.Reflesh(); }

	// �X�L���c���[���擾.
	const SkillTree &GetSkillTree() const { return Tree; }

	// �A�C�e�����X�g���擾.
	const ItemList &GetItemList() const { return Items; }

	// �A�C�e���ǉ�.
	void AddItem(uint32 ItemId, uint32 Count) { Items.Add(ItemId, Count); }

	// �A�C�e���폜.
	void SubtractItem(uint32 ItemId, uint32 Count) { Items.Subtract(ItemId, Count); }

	// �A�C�e���V���[�g�J�b�g���X�V.
	void UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2) { Items.UpdateItemShortcut(ItemId1, ItemId2); }

private:

	// Uuid
	uint32 Uuid;

	// ���O.
	FString Name;

	// �W���u
	uint8 Job;

	// ���x��
	uint32 Level;

	// �ő�HP
	int32 MaxHp;

	// STR
	int32 Str;

	// DEF
	int32 Def;

	// INT
	int32 Int;

	// MND
	int32 Mnd;

	// VIT
	int32 Vit;

	// �o���l.
	int32 Exp;

	// �S�[���h
	uint32 Gold;

	// �X�L�����X�g
	TArray<uint32> SkillList;

	// �X�L���c���[
	SkillTree Tree;

	// �A�C�e�����X�g
	ItemList Items;

};
