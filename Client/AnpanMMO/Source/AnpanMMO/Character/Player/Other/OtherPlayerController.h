// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "OtherPlayerController.generated.h"

class AOtherPlayerCharacter;

/**
 * ���l�̃R���g���[��
 */
UCLASS()
class ANPANMMO_API AOtherPlayerController : public AController
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	AOtherPlayerController(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AOtherPlayerController() {}

	// Pawn���R�t����ꂽ.
	virtual void Possess(APawn *aPawn) override;

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �ړ�.
	void Move(float X, float Y, float Z, float Rotation);

	// �ړ��x�N�g���̎擾.
	FVector GetMoveVector() const;

private:
	
	// �ړ��C���^�[�o��
	static const float MoveInterval;

	// �L�����N�^
	TWeakObjectPtr<AOtherPlayerCharacter> pCharacter;

	// �ړ����W.
	FVector MoveTarget;

	// �ȑO�̍��W.
	FVector PrevPos;

	// �ړ�����.
	float MoveTime;
	
};
