// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"
#include "PlayerStatus.h"
#include "PlayerMove.h"
#include "GameCharacter.generated.h"

class UFloatingPawnMovement;
class USkeletalMeshComponent;

/**
 * プレイヤーキャラクタクラス
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AGameCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AGameCharacter() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// ステータス取得.
	const PlayerStatus &GetStatus() const { return Status; }

	// 経験値を受信した。
	void OnRecvExp(int32 Exp);

	// レベルアップを受信した。
	void OnRecvLevelUp(int32 MaxHp, int32 Atk, int32 Def);

	// 移動ベクトルの取得.
	virtual FVector GetMoveVector() const override;

	// UUIDを取得.
	virtual uint32 GetUuid() const override { return Status.GetUuid(); }

	// キャラクタ名を取得.
	virtual FString GetCharacterName() const override { return Status.GetName(); }
	
	// キャラクタタイプを取得.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::Player; }

	// スキルが使用可能か？
	UFUNCTION(BlueprintPure, Category = "Skill")
	bool IsSkillUsable(int32 SkillId) const;

	// スキル使用.
	UFUNCTION(BlueprintCallable, Category = "Skill")
	void UseSkill(int32 SkillId);

protected:

	// レベルアップした
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

	// リスポンした。
	virtual void OnRespawn() override;

private:

	// ステータス
	PlayerStatus Status;

	// 移動パケット制御.
	PlayerMove Move;

};
