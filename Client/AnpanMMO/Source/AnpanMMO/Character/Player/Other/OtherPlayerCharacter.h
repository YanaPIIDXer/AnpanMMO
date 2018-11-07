// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Player/PlayerCharacterBase.h"
#include "OtherPlayerCharacter.generated.h"

/**
 * 他人のPlayerCharacter
 */
UCLASS()
class ANPANMMO_API AOtherPlayerCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()
	
public:

	// Spawn
	static AOtherPlayerCharacter *Spawn(UWorld *pWorld, const FVector &Position, const FRotator &Rotation);

	// コンストラクタ
	AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AOtherPlayerCharacter() {}

protected:

private:
	
	
};
