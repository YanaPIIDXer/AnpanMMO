// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "OtherPlayerController.generated.h"

class AOtherPlayerCharacter;

/**
 * 他人のコントローラ
 */
UCLASS()
class ANPANMMO_API AOtherPlayerController : public AController
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	AOtherPlayerController(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AOtherPlayerController() {}

	// Pawnが紐付けられた.
	virtual void Possess(APawn *aPawn) override;

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// 移動.
	void Move(float X, float Y, float Z, float Rotation);

	// 移動ベクトルの取得.
	FVector GetMoveVector() const;

private:
	
	// 移動インターバル
	static const float MoveInterval;

	// キャラクタ
	TWeakObjectPtr<AOtherPlayerCharacter> pCharacter;

	// 移動座標.
	FVector MoveTarget;

	// 以前の座標.
	FVector PrevPos;

	// 移動時間.
	float MoveTime;
	
};
