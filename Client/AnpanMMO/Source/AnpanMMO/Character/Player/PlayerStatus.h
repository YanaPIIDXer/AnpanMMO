// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Skill/SkillTree/SkillTree.h"
#include "Item/ItemList.h"

/**
 * プレイヤーステータス
 */
class ANPANMMO_API PlayerStatus
{

public:

	// コンストラクタ
	PlayerStatus();

	// デストラクタ
	~PlayerStatus() {}

	// Uuidセット
	void SetUuid(uint32 InUuid) { Uuid = InUuid; }

	// セット
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

	// 経験値セット
	void SetExp(int32 InExp) { Exp = InExp; }

	// 名前をセット
	void SetName(const FString &InName) { Name = InName; }

	// 名前を取得.
	const FString &GetName() const { return Name; }

	// Uuid取得.
	uint32 GetUuid() const { return Uuid; }

	// ジョブをセット
	void SetJob(uint8 InJob)
	{
		Job = InJob;
		Tree.Initialize(Job);
	}

	// ジョブを取得.
	u8 GetJob() const { return Job; }

	// ゴールドをセット
	void SetGold(uint32 InGold) { Gold = InGold; }

	// ゴールドを取得.
	uint32 GetGold() const { return Gold; }

	// レベルを取得.
	uint32 GetLevel() const { return Level; }

	// 最大HP取得.
	int32 GetMaxHp() const { return MaxHp; }

	// STR取得.
	int32 GetStr() const { return Str; }

	// DEF取得.
	int32 GetDef() const { return Def; }

	// INT取得.
	int32 GetInt() const { return Int; }

	// MND取得.
	int32 GetMnd() const { return Mnd; }

	// VIT取得.
	int32 GetVit() const { return Vit; }

	// 経験値取得.
	int32 GetExp() const { return Exp; }

	// スキルリストをセット。
	void SetSkillList(uint32 NormalAttack, uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4);

	// スキルリストを取得.
	const TArray<uint32> &GetSkillList() const { return SkillList; }

	// スキルツリーのノードを開く。
	void OpenSkillTreeNode(uint32 NodeId);

	// スキルツリーの再構築.
	void RefleshSkillTree() { Tree.Reflesh(); }

	// スキルツリーを取得.
	const SkillTree &GetSkillTree() const { return Tree; }

	// アイテムリストを取得.
	const ItemList &GetItemList() const { return Items; }

	// アイテム追加.
	void AddItem(uint32 ItemId, uint32 Count) { Items.Add(ItemId, Count); }

	// アイテム削除.
	void SubtractItem(uint32 ItemId, uint32 Count) { Items.Subtract(ItemId, Count); }

	// アイテムショートカットを更新.
	void UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2) { Items.UpdateItemShortcut(ItemId1, ItemId2); }

private:

	// Uuid
	uint32 Uuid;

	// 名前.
	FString Name;

	// ジョブ
	uint8 Job;

	// レベル
	uint32 Level;

	// 最大HP
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

	// 経験値.
	int32 Exp;

	// ゴールド
	uint32 Gold;

	// スキルリスト
	TArray<uint32> SkillList;

	// スキルツリー
	SkillTree Tree;

	// アイテムリスト
	ItemList Items;

};
