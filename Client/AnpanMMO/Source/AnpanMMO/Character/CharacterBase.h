// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Buff/BuffManager.h"
#include "Master/BuffMaster.h"
#include "CharacterBase.generated.h"

// キャラクタタイプ
UENUM(BlueprintType, Category = "Character")
enum class ECharacterType : uint8
{
	None UMETA(Hidden),

	// 自分
	Player,

	// 他人.
	Other,

	// アンパン.
	Anpan,

	// NPC
	NPC,
};

class ATargetCircle;
class ASkillRangeDecal;

/**
 * キャラクタ基底クラス
 */
UCLASS()
class ANPANMMO_API ACharacterBase : public ACharacter
{

	GENERATED_BODY()

public:

	// コンストラクタ
	ACharacterBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ACharacterBase() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 破棄された.
	UFUNCTION()
	void OnDestroy(AActor *pDestroyedActor);

	// ダメージを与える。
	void ApplyDamage(int32 Value);

	// 回復.
	void Heal(int32 Value);

	// 死んでる？
	bool IsDead() const { return (Hp <= 0); }

	// HP取得
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetHp() const { return Hp; }

	// 最大HP取得.
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetMaxHp() const { return MaxHp; }

	// 高さの半分を取得.
	virtual float GetHalfHeight() const { return 0.0f; }
	
	// キャラクタタイプを取得.
	UFUNCTION(BlueprintPure, Category = "Character")
	virtual ECharacterType GetCharacterType() const { return ECharacterType::None; }

	// ターゲットサークルを生成.
	void SpawnTargetCircle();

	// ターゲットサークルを撤去.
	void DestroyTargetCircle();

	// UUIDを取得.
	//virtual uint32 GetUuid() const = 0;
	virtual uint32 GetUuid() const { return 0; }

	// キャラクタ名を取得.
	//virtual FString GetCharacterName() const = 0;
	UFUNCTION(BlueprintPure, Category = "Character")
	virtual FString GetCharacterName() const { return ""; }

	// スキルキャストを受信した。
	virtual void OnSkillCast(uint32 SkillId);

	// スキルキャストが完了した。
	virtual void OnSkillCastFinished();

	// スキル発動を受信した。
	virtual void OnSkillActivate() {}

	// バフ追加.
	void AddBuff(uint32 BuffId);

	// バフ消去.
	void RemoveBuff(uint8 Type);

	// 麻痺状態か？
	UFUNCTION(BlueprintPure, Category = "Character")
	bool IsParalysis() const { return BuffMgr.IsActive(BuffItem::PARALYSIS); }

	// 移動速度レートを設定.
	void SetMoveSpeedRate(float Rate);

protected:

	// 初期化.
	void Initialize(int32 InHp, int32 InMaxHp);

	// 最大HPを更新.
	void UpdateMaxHp(int32 InMaxHp) { MaxHp = InMaxHp; }

	// ダメージイベント
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnDamaged(int32 BeforeHp, int32 AfterHp, int32 DamageValue);
	virtual void OnDamaged_Implementation(int32 BeforeHp, int32 AfterHp, int32 DamageValue) {}

	// 回復イベント
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnHeal(int32 BeforeHp, int32 AfterHp, int32 HealValue);
	void OnHeal_Implementation(int32 BeforeHp, int32 AfterHp, int32 HealValue) {}

	// 死亡イベント
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnDead();
	virtual void OnDead_Implementation() {}

	// HPを設定.
	void SetHP(int InHp) { Hp = InHp; }

	// バフが追加された。
	virtual void OnAddedBuff(uint32 BuffId) {}

	// バフが消滅した。
	virtual void OnRemovedBuff(uint8 Type) {}

private:

	// 基礎移動速度.
	static const float BaseMoveSpeed;

	// HP
	int32 Hp;

	// 最大HP
	int32 MaxHp;

	// ターゲットサークル
	UPROPERTY()
	ATargetCircle *pTargetCircle;

	// スキルの範囲デカール
	UPROPERTY()
	ASkillRangeDecal *pSkillRangeDecal;

	// バフ管理.
	BuffManager BuffMgr;
	

	// スキルの範囲デカールを破棄.
	void DestroySkillRangeDecal();

};
