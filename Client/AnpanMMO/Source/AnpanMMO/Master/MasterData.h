// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AreaMaster.h"
#include "WarpDataMaster.h"
#include "WarpPointMaster.h"
#include "AnpanMaster.h"
#include "TimeInfoMaster.h"
#include "NPCMaster.h"
#include "NPCResourceMaster.h"
#include "NPCConditionMaster.h"
#include "SkillMaster.h"
#include "SkillTreeMaster.h"
#include "ItemMaster.h"
#include "QuestMaster.h"
#include "QuestStageMaster.h"
#include "QuestRewardMaster.h"
#include "EquipMaster.h"
#include "BuffMaster.h"

/**
 * マスタデータ
 */
class ANPANMMO_API MasterData : FNoncopyable
{

public:

	// デストラクタ
	~MasterData() {}

	// ロード
	void Load();

	// エリアマスタを取得.
	const AreaMaster &GetAreaMaster() const { return Area; }

	// ワープポイントマスタを取得.
	const WarpPointMaster &GetWarpPointMaster() const { return WarpPoint; }

	// ワープデータマスタを取得.
	const WarpDataMaster &GetWarpDataMaster() const { return WarpData; }

	// アンパンマスタを取得.
	const AnpanMaster &GetAnpanMaster() const { return Anpan; }

	// 時間情報マスタを取得.
	const TimeInfoMaster &GetTimeInfoMaster() const { return TimeInfo; }

	// NPCマスタを取得.
	const NPCMaster &GetNPCMaster() const { return NPC; }

	// NPCリソースマスタを取得.
	const NPCResourceMaster &GetNPCReseourceMaster() const { return NPCResource; }

	// NPCコンディションマスタを取得.
	const NPCConditionMaster &GetNPCConditionMaster() const { return NPCCondition; }

	// スキルマスタ取得.
	const SkillMaster &GetSkillMaster() const { return Skill; }

	// スキルツリーマスタ取得.
	const SkillTreeMaster &GetSkillTreeMaster() const { return SkillTree; }

	// アイテムマスタ取得.
	const ItemMaster &GetItemMaster() const { return Item; }

	// クエストマスタ取得.
	const QuestMaster &GetQuestMaster() const { return Quest; }

	// クエストステージマスタ取得.
	const QuestStageMaster &GetQuestStageMaster() const { return QuestStage; }

	// クエスト報酬マスタ取得.
	const QuestRewardMaster &GetQuestRewardMaster() const { return QuestReward; }

	// 装備マスタ取得.
	const EquipMaster &GetEquipMaster() const { return Equip; }

	// バフマスタ取得.
	const BuffMaster &GetBuffMaster() const { return Buff; }

private:

	// エリアマスタ
	AreaMaster Area;

	// ワープポイントマスタ
	WarpPointMaster WarpPoint;

	// ワープデータマスタ
	WarpDataMaster WarpData;

	// アンパンマスタ
	AnpanMaster Anpan;

	// 時間情報マスタ
	TimeInfoMaster TimeInfo;

	// NPCマスタ
	NPCMaster NPC;

	// NPCリソースマスタ
	NPCResourceMaster NPCResource;

	// NPCコンディションマスタ
	NPCConditionMaster NPCCondition;

	// スキルマスタ
	SkillMaster Skill;

	// スキルツリーマスタ
	SkillTreeMaster SkillTree;

	// アイテムマスタ
	ItemMaster Item;

	// クエストマスタ
	QuestMaster Quest;

	// クエストステージマスタ
	QuestStageMaster QuestStage;

	// クエスト報酬マスタ
	QuestRewardMaster QuestReward;

	// 装備マスタ
	EquipMaster Equip;

	// バフマスタ
	BuffMaster Buff;

	// =========== Singleton ============
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData();
	static MasterData Instance;
};
