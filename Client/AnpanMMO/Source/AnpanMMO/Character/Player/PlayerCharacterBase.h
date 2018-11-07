// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Components/SkeletalMeshComponent.h"
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

protected:

	// MeshComponent取得.
	USkeletalMeshComponent *GetMeshComponent() const { return pMeshComponent; }

private:

	// メッシュパス
	static const TCHAR *MeshPath;

	// MeshComponent
	UPROPERTY()
	USkeletalMeshComponent *pMeshComponent;

};
