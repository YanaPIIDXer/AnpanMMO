// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameCamera.h"
#include "GameCharacter.h"
#include "GameController.generated.h"

/**
 * コントローラクラス
 */
UCLASS()
class ANPANMMO_API AGameController : public APlayerController
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	AGameController(const FObjectInitializer &ObjectInitializer);
	
	// デストラクタ
	virtual ~AGameController() {}

	// Pawnが紐付けられた。
	virtual void Possess(APawn *aPawn) override;

	// タッチ入力.
	virtual bool InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D &TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;

private:
	
	// 前後移動のバインド名.
	static const FName MoveForwardBind;

	// 左右移動のバインド名.
	static const FName MoveRightBind;

	// 攻撃のバインド名.
	static const FName AttackBind;

	// プレイヤーキャラ
	TWeakObjectPtr<AGameCharacter> pCharacter;

	// カメラ
	TWeakObjectPtr<AGameCamera> pCamera;

	// 以前のタッチ座標.
	FVector2D PrevTouchLocation;


	// カメラをSpawn
	void SpawnCamera();

	// PlayerInputComponentのセットアップ
	void SetupPlayerInput(UInputComponent *pInputComponent);

	// 前後移動.
	void MoveForward(float Value);

	// 左右移動.
	void MoveRight(float Value);

};
