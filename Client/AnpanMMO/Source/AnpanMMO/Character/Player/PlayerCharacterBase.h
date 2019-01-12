// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacterBase.generated.h"

/**
 * プレイヤーキャラ基底クラス
 */
UCLASS(Abstract)
class ANPANMMO_API APlayerCharacterBase : public ACharacterBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	APlayerCharacterBase(const FObjectInitializer &ObjectInitializer);
	
	// デストラクタ
	virtual ~APlayerCharacterBase() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 移動.
	virtual void Move(float X, float Y, float Z, float Rotation) {}

	// 移動ベクトルの取得.
	virtual FVector GetMoveVector() const { return FVector(); }

	// リスポン.
	void Respawn();

	// 高さの半分を取得.
	virtual float GetHalfHeight() const override { return GetCapsuleComponent()->GetScaledCapsuleHalfHeight(); }

protected:

	// リスポンした
	virtual void OnRespawn() {}

	// AnimBPのクラス
	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimBlueprintGeneratedClass *pAnimClass;

private:

	// メッシュパス
	static const TCHAR *MeshPath;

};
