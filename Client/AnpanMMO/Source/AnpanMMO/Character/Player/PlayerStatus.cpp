// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerStatus.h"

// �R���X�g���N�^
PlayerStatus::PlayerStatus()
	: Uuid(0)
	, Name("")
	, Level(1)
	, MaxHp(1)
	, Atk(10)
	, Def(10)
	, Exp(0)
	, Gold(0)
{
}

// �X�L�����X�g���Z�b�g�B
void PlayerStatus::SetSkillList(uint32 NormalAttack, uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4)
{
	SkillList.Empty();
	SkillList.Add(NormalAttack);
	SkillList.Add(Skill1);
	SkillList.Add(Skill2);
	SkillList.Add(Skill3);
	SkillList.Add(Skill4);
}

// �X�L���c���[�̃m�[�h���J���B
void PlayerStatus::OpenSkillTreeNode(uint32 NodeId)
{
	Tree.Open(NodeId);
}
