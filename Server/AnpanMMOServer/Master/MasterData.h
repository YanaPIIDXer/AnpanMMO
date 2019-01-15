/**
 * @file MasterData.h
 * @brief マスタデータクラス
 * @author YanaP
 */
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
#include "QuestMaster.h"
#include "QuestStageMaster.h"
#include "QuestRewardMaster.h"
#include "LevelMaster.h"
#include "EquipMaster.h"
#include "BuffMaster.h"

/**
 * @class MasterData
 * @brief マスタデータクラス
 * @detail シングルトンクラス
 */
class MasterData : public noncopyable
{

public:

	/**
	 * @fn bool Read()
	 * @brief 読み込み
	 * @return 成功したらtrueを返す
	 */
	bool Read();

	/**
	 * @fn const AreaMaster &GetAreaMaster()
	 * @brief エリアマスタ取得
	 * @return エリアマスタ
	 */
	const AreaMaster &GetAreaMaster() { return Area; }

	/**
	 * @fn const WarpDataMaster &GetWarpDataMaster()
	 * @brief ワープデータマスタ取得
	 * @return ワープデータマスタ
	 */
	const WarpDataMaster &GetWarpDataMaster() { return WarpData; }

	/**
	 * @fn const AnpanMaster &GetAnpanMaster()
	 * @brief アンパンマスタ取得
	 * @return アンパンマスタ
	 */
	const AnpanMaster &GetAnpanMaster() { return Anpan; }

	/**
	 * @fn const AnpanPopAreaMaster &GetAnpanPopAreaMaster()
	 * @brief アンパンポップエリアマスタ取得
	 * @return アンパンポップエリアマスタ
	 */
	const AnpanPopAreaMaster &GetAnpanPopAreaMaster() { return AnpanPopArea; }

	/**
	 * @fn const AnpanPopDataMaster &GetAnpanPopDataMaster()
	 * @brief アンパンポップデータマスタ取得
	 * @return アンパンポップデータマスタ
	 */
	const AnpanPopDataMaster &GetAnpanPopDataMaster() { return AnpanPopData; }

	/**
	 * @fn const InstanceInfoMaster &GetInstanceInfoMaster()
	 * @brief インスタンスエリア情報マスタ取得
	 * @return インスタンスエリア情報マスタ
	 */
	const InstanceInfoMaster &GetInstanceInfoMaster() { return InstanceInfo; }

	/**
	 * @fn const TimeInfoMaster &GetTimeInfoMaster()
	 * @brief 時間情報マスタ取得
	 * @return 時間情報マスタ
	 */
	const TimeInfoMaster &GetTimeInfoMaster() { return TimeInfo; }

	/**
	 * @fn const NPCMaster &GetNPCMaster()
	 * @brief ＮＰＣマスタ取得
	 * @return ＮＰＣマスタ
	 */
	const NPCMaster &GetNPCMaster() { return NPC; }

	/**
	 * @fn const SkillMaster &GetSkillMaster()
	 * @brief スキルマスタ取得
	 * @return スキルマスタ
	 */
	const SkillMaster &GetSkillMaster() { return Skill; }

	/**
	 * @fn const SkillTreeMaster &GetSkillTreeMaster()
	 * @brief スキルツリーマスタ取得
	 * @return スキルツリーマスタ
	 */
	const SkillTreeMaster &GetSkillTreeMaster() { return SkillTree; }

	/**
	 * @fn const ItemMaster &GetItemMaster()
	 * @brief アイテムマスタ取得
	 * @return アイテムマスタ
	 */
	const ItemMaster &GetItemMaster() { return Item; }

	/**
	 * @fn const ItemDropMaster &GetItemDropMaster()
	 * @brief アイテムドロップマスタ取得
	 * @return アイテムドロップマスタ
	 */
	const ItemDropMaster &GetItemDropMaster() { return ItemDrop; }

	/**
	 * @fn const QuestMaster &GetQuestMaster()
	 * @brief クエストマスタ取得
	 * @return クエストマスタ
	 */
	const QuestMaster &GetQuestMaster() { return Quest; }

	/**
	 * @fn const QuestStageMaster &GetQuestStageMaster()
	 * @brief クエストステージマスタ取得
	 * @return クエストステージマスタ
	 */
	const QuestStageMaster &GetQuestStageMaster() { return QuestStage; }

	/**
	 * @fn const QuestRewardMaster &GetQuestRewardMaster()
	 * @brief クエスト報酬マスタ取得
	 * @return クエスト報酬マスタ
	 */
	const QuestRewardMaster &GetQuestRewardMaster() { return QuestReward; }

	/**
	 * @fn const LevelMaster &GetLevelMaster()
	 * @brief レベルマスタ取得
	 * @return レベルマスタ
	 */
	const LevelMaster &GetLevelMaster() { return Level; }

	/**
	 * @fn const EquipMaster &GetEquipMaster()
	 * @brief 装備マスタ取得
	 * @return 装備マスタ
	 */
	const EquipMaster &GetEquipMaster() { return Equip; }

	/**
	 * @fn const BuffMaster &GetBuffMaster()
	 * @brief バフマスタ取得
	 * @return バフマスタ
	 */
	const BuffMaster &GetBuffMaster() { return Buff; }

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

	// クエストマスタ
	QuestMaster Quest;

	// クエストステージマスタ
	QuestStageMaster QuestStage;

	// クエスト報酬マスタ
	QuestRewardMaster QuestReward;

	// レベルマスタ
	LevelMaster Level;

	// 装備マスタ
	EquipMaster Equip;

	// バフマスタ
	BuffMaster Buff;

	// ======= Singleton ==========
public:

	/**
	 * @fn static MasterData &GetInstance()
	 * @brief インスタンス取得
	 * @return シングルトンインスタンス
	 */
	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__
