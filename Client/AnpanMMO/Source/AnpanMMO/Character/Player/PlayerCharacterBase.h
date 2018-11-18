// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "PlayerCharacterBase.generated.h"

/**
 * �v���C���[�L�������N���X
 */
UCLASS()
class ANPANMMO_API APlayerCharacterBase : public ACharacterBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	APlayerCharacterBase(const FObjectInitializer &ObjectInitializer);
	
	// �f�X�g���N�^
	virtual ~APlayerCharacterBase() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// �ړ�.
	virtual void Move(float X, float Y, float Z, float Rotation) {}

	// �ړ��x�N�g���̎擾.
	virtual FVector GetMoveVector() const { return FVector(); }

	// ���X�|��.
	void Respawn();
	
protected:

	// ���X�|������
	virtual void OnRespawn() {}

private:

	// ���b�V���p�X
	static const TCHAR *MeshPath;

	// AnimInstance�̃N���X�p�X
	static const TCHAR *AnimInstanceClassPath;

};
