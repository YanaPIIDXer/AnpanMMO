// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "PlayerStatus.h"
#include "GameCharacter.generated.h"

class UFloatingPawnMovement;
class USkeletalMeshComponent;

/**
 * プレイヤーキャラクタクラス
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public ACharacterBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AGameCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AGameCharacter() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 攻撃.
	void Attack();

	// ステータス取得.
	const PlayerStatus &GetStatus() const { return Status; }

private:

	// メッシュパス
	static const TCHAR *MeshPath;

	// AnimInstanceのクラスパス
	static const TCHAR *AnimInstanceClassPath;

	// 移動用Component
	UPROPERTY()
	UFloatingPawnMovement *pMovementComponent;

	// MeshComponent
	UPROPERTY()
	USkeletalMeshComponent *pMeshComponent;

	// ステータス
	PlayerStatus Status;

};
