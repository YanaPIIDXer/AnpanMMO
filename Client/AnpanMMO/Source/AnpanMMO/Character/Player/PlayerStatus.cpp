// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerStatus.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
PlayerStatus::PlayerStatus()
	: Uuid(0)
	, Name("")
	, Level(1)
	, MaxHp(1)
	, BaseMaxHp(1)
	, Str(10)
	, Def(10)
	, Int(10)
	, Mnd(10)
	, Vit(10)
	, Exp(0)
	, Gold(0)
	, RightEquipId(0)
	, LeftEquipId(0)
{
	// �ʏ�U���{�X�L���S���B
	SkillList.Add(0);
	SkillList.Add(0);
	SkillList.Add(0);
	SkillList.Add(0);
	SkillList.Add(0);
}

// �������Z�b�g
void PlayerStatus::SetEquip(uint32 InRightEquipId, uint32 InLeftEquipId)
{
	RightEquipId = InRightEquipId;
	LeftEquipId = InLeftEquipId;

	// �E�葕���ɐݒ肳�ꂽ�X�L����ʏ�U���Ƃ���B
	const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().Get(RightEquipId);
	if (pItem == nullptr)
	{
		SkillList[0] = 0;
		return;
	}
	SkillList[0] = pItem->NormalAttackId;
}

// �X�L�����X�g���Z�b�g�B
void PlayerStatus::SetSkillList(uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4)
{
	SkillList[1] = Skill1;
	SkillList[2] = Skill2;
	SkillList[3] = Skill3;
	SkillList[4] = Skill4;
}

// �X�L���c���[�̃m�[�h���J���B
void PlayerStatus::OpenSkillTreeNode(uint32 NodeId)
{
	Tree.Open(NodeId);
}
