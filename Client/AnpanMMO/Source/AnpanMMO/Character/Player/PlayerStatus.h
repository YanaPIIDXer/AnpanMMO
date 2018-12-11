// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

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
	void Set(int32 InMaxHp, int32 InAtk, int32 InDef)
	{
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
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
	void SetJob(uint8 InJob) { Job = InJob; }

	// ジョブを取得.
	u8 GetJob() const { return Job; }

	// 最大HP取得.
	int32 GetMaxHp() const { return MaxHp; }

	// 攻撃力取得.
	int32 GetAtk() const { return Atk; }

	// 防御力取得.
	int32 GetDef() const { return Def; }

	// 経験値取得.
	int32 GetExp() const { return Exp; }

	// スキルリストをセット。
	void SetSkillList(uint32 NormalAttack, uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4);

	// スキルリストを取得.
	const TArray<uint32> &GetSkillList() const { return SkillList; }

private:

	// Uuid
	uint32 Uuid;

	// 名前.
	FString Name;

	// ジョブ
	uint8 Job;

	// 最大HP
	int32 MaxHp;

	// 攻撃力.
	int32 Atk;

	// 防御力.
	int32 Def;

	// 経験値.
	int32 Exp;

	// スキルリスト
	TArray<uint32> SkillList;

};
