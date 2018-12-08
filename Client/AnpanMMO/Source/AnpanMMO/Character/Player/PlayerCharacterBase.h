// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacterBase.generated.h"

/**
 * �v���C���[�L�������N���X
 */
UCLASS(Abstract)
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

	// �����̔������擾.
	virtual float GetHalfHeight() const override { return GetCapsuleComponent()->GetScaledCapsuleHalfHeight(); }

	// UUID���擾.
	//virtual uint32 GetUuid() const = 0;
	virtual uint32 GetUuid() const { return 0; }

	// �L�����N�^�����擾.
	//virtual FString GetCharacterName() const = 0;
	UFUNCTION(BlueprintPure, Category = "Character")
	virtual FString GetCharacterName() const { return ""; }

protected:

	// ���X�|������
	virtual void OnRespawn() {}

private:

	// ���b�V���p�X
	static const TCHAR *MeshPath;

	// AnimInstance�̃N���X�p�X
	static const TCHAR *AnimInstanceClassPath;

};
