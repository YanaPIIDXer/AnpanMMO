// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacterBase.generated.h"

/**
 * プレイヤーキャラ基底クラス
 */
UCLASS()
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
	float GetHalfHeight() const { return GetCapsuleComponent()->GetScaledCapsuleHalfHeight(); }
	
protected:

	// リスポンした
	virtual void OnRespawn() {}

private:

	// メッシュパス
	static const TCHAR *MeshPath;

	// AnimInstanceのクラスパス
	static const TCHAR *AnimInstanceClassPath;

};
