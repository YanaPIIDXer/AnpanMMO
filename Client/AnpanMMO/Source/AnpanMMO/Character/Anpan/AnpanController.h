// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "AnpanController.generated.h"

class AAnpan;

/**
 * アンパンコントローラクラス
 */
UCLASS()
class ANPANMMO_API AAnpanController : public AController
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AAnpanController(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AAnpanController() {}

	// Pawnが紐付けられた.
	virtual void Possess(APawn *aPawn) override;

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// 移動.
	void Move(float X, float Y, float Z, int32 Time);

	// 回転.
	void Rotate(float Rotation, int32 Time);

	// 停止.
	void Stop(float X, float Y, float Z, float Rotation);

private:
	
	// アンパン.
	TWeakObjectPtr<AAnpan> pAnpan;

	// 移動先.
	FVector MoveTarget;

	// 以前の座標。
	FVector PrevPos;

	// 移動時間.
	float MoveTime;

	// 移動開始時間.
	float MoveStartTime;

	// 回転先.
	float RotateTarget;

	// 以前の回転.
	float PrevRotate;

	// 回転時間.
	float RotateTime;

	// 回転開始時間.
	float RotateStartTime;


	// 移動更新.
	void UpdateMove(float DeltaTime);

	// 回転更新.
	void UpdateRotation(float DeltaTime);

};
