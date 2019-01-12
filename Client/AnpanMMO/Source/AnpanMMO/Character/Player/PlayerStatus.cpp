// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerStatus.h"
#include "Master/MasterData.h"

// コンストラクタ
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
	// 通常攻撃＋スキル４つ分。
	SkillList.Add(0);
	SkillList.Add(0);
	SkillList.Add(0);
	SkillList.Add(0);
	SkillList.Add(0);
}

// 装備をセット
void PlayerStatus::SetEquip(uint32 InRightEquipId, uint32 InLeftEquipId)
{
	RightEquipId = InRightEquipId;
	LeftEquipId = InLeftEquipId;

	// 右手装備に設定されたスキルを通常攻撃とする。
	const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().Get(RightEquipId);
	if (pItem == nullptr)
	{
		SkillList[0] = 0;
		return;
	}
	SkillList[0] = pItem->NormalAttackId;
}

// スキルリストをセット。
void PlayerStatus::SetSkillList(uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4)
{
	SkillList[1] = Skill1;
	SkillList[2] = Skill2;
	SkillList[3] = Skill3;
	SkillList[4] = Skill4;
}

// スキルツリーのノードを開く。
void PlayerStatus::OpenSkillTreeNode(uint32 NodeId)
{
	Tree.Open(NodeId);
}
