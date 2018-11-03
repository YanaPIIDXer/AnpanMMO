// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

/**
 * �L�����N�^�N���X
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public ACharacter
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

	// InputComponent�̃Z�b�g�A�b�v
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	
};
