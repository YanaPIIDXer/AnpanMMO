// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerStatus.h"

// コンストラクタ
PlayerStatus::PlayerStatus()
	: Uuid(0)
	, Name("")
	, MaxHp(1)
	, Atk(10)
	, Def(10)
	, Exp(0)
	, Gold(0)
{
}

// スキルリストをセット。
void PlayerStatus::SetSkillList(uint32 NormalAttack, uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4)
{
	SkillList.Empty();
	SkillList.Add(NormalAttack);
	SkillList.Add(Skill1);
	SkillList.Add(Skill2);
	SkillList.Add(Skill3);
	SkillList.Add(Skill4);
}
