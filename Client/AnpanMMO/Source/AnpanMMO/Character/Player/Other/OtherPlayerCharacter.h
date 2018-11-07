// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Player/PlayerCharacterBase.h"
#include "OtherPlayerCharacter.generated.h"

/**
 * ���l��PlayerCharacter
 */
UCLASS()
class ANPANMMO_API AOtherPlayerCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()
	
public:

	// Spawn
	static AOtherPlayerCharacter *Spawn(UWorld *pWorld, const FVector &Position, const FRotator &Rotation);

	// �R���X�g���N�^
	AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AOtherPlayerCharacter() {}

protected:

private:
	
	
};
