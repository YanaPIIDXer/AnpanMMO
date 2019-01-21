// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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
	virtual void OnPossess(APawn *aPawn) override;

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �^�b�`����.
	virtual bool InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D &TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;

	// �����邩�ǂ�����ݒ�.
	void SetEnableMove(bool bInEnableMove) { bEnableMove = bInEnableMove; }

	// �^�[�Q�b�g���擾.
	UFUNCTION(BlueprintPure, Category = "Target")
	ACharacterBase *GetCurrentTarget() const { return pCurrentTarget.Get(); }

private:
	
	// �O��ړ��̃o�C���h��.
	static const FName MoveForwardBind;

	// ���E�ړ��̃o�C���h��.
	static const FName MoveRightBind;

	// �U���̃o�C���h��.
	static const FName AttackBind;

	// �^�b�v�`�F�b�N��臒l.
	static const float TapCheckThreshold;

	// �v���C���[�L����
	TWeakObjectPtr<AGameCharacter> pCharacter;

	// �J����
	TWeakObjectPtr<AGameCamera> pCamera;

	// ���̓x�N�g��.
	FVector InputVector;

	// �ȑO�̃^�b�`���W.
	FVector2D PrevTouchLocation;

	// �����邩�H
	bool bEnableMove;

	// �X���C�v��.
	float SwipeValue;

	// ���݂̃^�[�Q�b�g
	TWeakObjectPtr<ACharacterBase> pCurrentTarget;

	// �^�[�Q�b�g�����邩�H
	// ���^�[�Q�b�g���ˑR���������̃P�[�X�ɑΉ����邽�߂ɕK�v�B
	bool bHasTarget;


	// �J������Spawn
	void SpawnCamera();

	// PlayerInputComponent�̃Z�b�g�A�b�v
	void SetupPlayerInput(UInputComponent *pInputComponent);

	// �ړ�����.
	void MoveProc();

	// �O��ړ�.
	void MoveForward(float Value);

	// ���E�ړ�.
	void MoveRight(float Value);

	// �^�[�Q�b�g�����߂邽�߂̃��C�g���[�X
	void RayTraceForTarget(const FVector2D &ScreenPos);

	// �^�[�Q�b�g�؂�ւ��ʒm.
	void NoticeTargetChanged();

};
