// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterBase.generated.h"

/**
 * キャラクタ基底クラス
 */
UCLASS()
class ANPANMMO_API ACharacterBase : public APawn
{
	GENERATED_BODY()

public:

	// コンストラクタ
	ACharacterBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ACharacterBase() {}

	// ダメージを与える。
	void ApplyDamage(int32 Value);

	// 死んでる？
	bool IsDead() const { return (Hp <= 0); }

	// HP取得
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetHp() const { return Hp; }

	// 最大HP取得.
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetMaxHp() const { return MaxHp; }

protected:

	// 初期化.
	void Initialize(int32 InHp, int32 InMaxHp);

	// 死亡イベント
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnDead();
	void OnDead_Implementation() {}

private:

	// HP
	int32 Hp;

	// 最大HP
	int32 MaxHp;
	
};
