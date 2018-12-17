// Copyright 2018 YanaPIIDXer All Rights Reserved.

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
	const ItemMaster &GetITemMaster() const { return Item; }

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

	// =========== Singleton ============
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData();
	static MasterData Instance;
};
