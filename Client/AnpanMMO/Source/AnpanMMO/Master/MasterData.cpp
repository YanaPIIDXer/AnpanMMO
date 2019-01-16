// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "MasterData.h"

MasterData MasterData::Instance;

// コンストラクタ
MasterData::MasterData()
{
}

// ロード
void MasterData::Load()
{
	Area.Load();
	WarpPoint.Load();
	WarpData.Load();
	Anpan.Load();
	TimeInfo.Load();
	NPC.Load();
	NPCResource.Load();
	NPCCondition.Load();
	Skill.Load();
	SkillTree.Load();
	Item.Load();
	Quest.Load();
	QuestStage.Load();
	QuestReward.Load();
	Equip.Load();
	Buff.Load();
}
