// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "GameCharacter.generated.h"

class UFloatingPawnMovement;

/**
 * �v���C���[�L�����N�^�N���X
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public ACharacterBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AGameCharacter(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AGameCharacter() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �U��.
	void Attack();

private:

	// �ړ��pComponent
	UPROPERTY()
	UFloatingPawnMovement *pMovementComponent;

};
