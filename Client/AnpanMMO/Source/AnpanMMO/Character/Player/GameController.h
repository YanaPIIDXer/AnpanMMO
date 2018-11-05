// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameCamera.h"
#include "GameCharacter.h"
#include "GameController.generated.h"

/**
 * �R���g���[���N���X
 */
UCLASS()
class ANPANMMO_API AGameController : public APlayerController
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	AGameController(const FObjectInitializer &ObjectInitializer);
	
	// �f�X�g���N�^
	virtual ~AGameController() {}

	// Pawn���R�t����ꂽ�B
	virtual void Possess(APawn *aPawn) override;

private:
	
	// �O��ړ��̃o�C���h��.
	static const FName MoveForwardBind;

	// ���E�ړ��̃o�C���h��.
	static const FName MoveRightBind;

	// �U���̃o�C���h��.
	static const FName AttackBind;

	// �v���C���[�L����
	TWeakObjectPtr<AGameCharacter> pCharacter;

	// �J����
	TWeakObjectPtr<AGameCamera> pCamera;


	// �J������Spawn
	void SpawnCamera();

	// PlayerInputComponent�̃Z�b�g�A�b�v
	void SetupPlayerInput(UInputComponent *pInputComponent);

	// �O��ړ�.
	void MoveForward(float Value);

	// ���E�ړ�.
	void MoveRight(float Value);

};
