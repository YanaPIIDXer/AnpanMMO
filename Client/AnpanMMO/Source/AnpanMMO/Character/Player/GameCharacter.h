// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "GameCharacter.generated.h"

class UFloatingPawnMovement;

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

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// 攻撃.
	void Attack();

private:

	// 移動用Component
	UPROPERTY()
	UFloatingPawnMovement *pMovementComponent;

};
