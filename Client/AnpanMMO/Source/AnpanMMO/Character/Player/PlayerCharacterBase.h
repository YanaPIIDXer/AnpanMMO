// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
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

private:
	
};
