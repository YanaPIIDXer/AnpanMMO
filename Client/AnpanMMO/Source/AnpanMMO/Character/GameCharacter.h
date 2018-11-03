// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

/**
 * キャラクタクラス
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public ACharacter
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

	// InputComponentのセットアップ
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	
};
