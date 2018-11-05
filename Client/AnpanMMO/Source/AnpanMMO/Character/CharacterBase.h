// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterBase.generated.h"

/**
 * キャラクタ基底クラス
 */
UCLASS()
class ANPANMMO_API ACharacterBase : public APawn
{
	GENERATED_BODY()

public:

	// コンストラクタ
	ACharacterBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ACharacterBase() {}

protected:

private:
	
};
