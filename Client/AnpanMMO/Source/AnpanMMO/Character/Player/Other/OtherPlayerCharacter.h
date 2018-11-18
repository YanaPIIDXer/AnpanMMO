// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Player/PlayerCharacterBase.h"
#include "OtherPlayerCharacter.generated.h"

class AOtherPlayerController;

/**
 * ���l��PlayerCharacter
 */
UCLASS()
class ANPANMMO_API AOtherPlayerCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()
	
public:

	// Spawn
	static AOtherPlayerCharacter *Spawn(UWorld *pWorld, const FVector &Position, const FRotator &Rotation, int32 Hp, int32 MaxHp);

	// �R���X�g���N�^
	AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AOtherPlayerCharacter() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// �R���g���[���ƕR�t����ꂽ�B
	virtual void PossessedBy(AController *NewController) override;

	// �ړ�.
	virtual void Move(float X, float Y, float Z, float Rotation) override;

	// �ړ��x�N�g���̎擾.
	virtual FVector GetMoveVector() const override;

protected:

private:

	// Blueprint�̃A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
	// �R���g���[��
	TWeakObjectPtr<AOtherPlayerController> pController;
	
};
