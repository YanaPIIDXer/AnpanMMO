#ifndef __MASTERDATA_H__
#define __MASTERDATA_H__

#include "AreaMaster.h"
#include "WarpDataMaster.h"
#include "AnpanMaster.h"
#include "AnpanPopAreaMaster.h"
#include "AnpanPopDataMaster.h"
#include "InstanceInfoMaster.h"
#include "TimeInfoMaster.h"
#include "NPCMaster.h"
#include "SkillMaster.h"
#include "SkillTreeMaster.h"
#include "ItemMaster.h"
#include "ItemDropMaster.h"

/**
 * マスタデータクラス
 */
class MasterData : public noncopyable
{

public:

	// 読み込み
	bool Read();

	// エリアマスタ取得.
	const AreaMaster &GetAreaMaster() { return Area; }

	// ワープデータマスタ取得.
	const WarpDataMaster &GetWarpDataMaster() { return WarpData; }

	// アンパンマスタ取得.
	const AnpanMaster &GetAnpanMaster() { return Anpan; }

	// アンパンポップエリアマスタ取得.
	const AnpanPopAreaMaster &GetAnpanPopAreaMaster() { return AnpanPopArea; }

	// アンパンポップデータマスタ取得.
	const AnpanPopDataMaster &GetAnpanPopDataMaster() { return AnpanPopData; }

	// インスタンスマップ情報マスタ取得.
	const InstanceInfoMaster &GetInstanceInfoMaster() { return InstanceInfo; }

	// 時間情報マスタ取得.
	const TimeInfoMaster &GetTimeInfoMaster() { return TimeInfo; }

	// NPCマスタを取得.
	const NPCMaster &GetNPCMaster() { return NPC; }

	// スキルマスタ取得.
	const SkillMaster &GetSkillMaster() { return Skill; }

	// スキルツリーマスタ取得.
	const SkillTreeMaster &GetSkillTreeMaster() { return SkillTree; }

	// アイテムマスタ取得.
	const ItemMaster &GetItemMaster() { return Item; }

	// アイテムドロップマスタ取得.
	const ItemDropMaster &GetItemDropMaster() { return ItemDrop; }

private:

	// DBホスト
	static const char *DBHost;

	// DB名.
	static const char *DBName;

	// DBのユーザ名とか記述したファイル名.
	static const std::string DBDataFileName;

	// エリアマスタ
	AreaMaster Area;

	// ワープデータマスタ
	WarpDataMaster WarpData;

	// アンパンマスタ
	AnpanMaster Anpan;

	// アンパンポップエリアマスタ
	AnpanPopAreaMaster AnpanPopArea;

	// アンパンポップデータマスタ
	AnpanPopDataMaster AnpanPopData;

	// インスタンスマップ情報マスタ
	InstanceInfoMaster InstanceInfo;

	// 時間情報マスタ
	TimeInfoMaster TimeInfo;

	// NPCマスタ
	NPCMaster NPC;

	// スキルマスタ
	SkillMaster Skill;

	// スキルツリーマスタ
	SkillTreeMaster SkillTree;

	// アイテムマスタ
	ItemMaster Item;

	// アイテムドロップマスタ
	ItemDropMaster ItemDrop;

	// ======= Singleton ==========
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__
