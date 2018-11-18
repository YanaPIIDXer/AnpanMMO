// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "AnpanController.generated.h"

class AAnpan;

/**
 * �A���p���R���g���[���N���X
 */
UCLASS()
class ANPANMMO_API AAnpanController : public AController
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AAnpanController(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AAnpanController() {}

	// Pawn���R�t����ꂽ.
	virtual void Possess(APawn *aPawn) override;

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �ړ�.
	void Move(float X, float Y, float Z, int32 Time);

	// ��].
	void Rotate(float Rotation, int32 Time);

	// ��~.
	void Stop(float X, float Y, float Z, float Rotation);

private:
	
	// �A���p��.
	TWeakObjectPtr<AAnpan> pAnpan;

	// �ړ���.
	FVector MoveTarget;

	// �ȑO�̍��W�B
	FVector PrevPos;

	// �ړ�����.
	float MoveTime;

	// �ړ��J�n����.
	float MoveStartTime;

	// ��]��.
	float RotateTarget;

	// �ȑO�̉�].
	float PrevRotate;

	// ��]����.
	float RotateTime;

	// ��]�J�n����.
	float RotateStartTime;


	// �ړ��X�V.
	void UpdateMove(float DeltaTime);

	// ��]�X�V.
	void UpdateRotation(float DeltaTime);

};
