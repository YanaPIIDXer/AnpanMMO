// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"
#include "PlayerStatus.h"
#include "GameCharacter.generated.h"

class UFloatingPawnMovement;
class USkeletalMeshComponent;

/**
 * �v���C���[�L�����N�^�N���X
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AGameCharacter(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AGameCharacter() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// �U��.
	void Attack();

	// �X�e�[�^�X�擾.
	const PlayerStatus &GetStatus() const { return Status; }

	// �o���l����M�����B
	void OnRecvExp(int32 Exp);

	// ���x���A�b�v����M�����B
	void OnRecvLevelUp(int32 MaxHp, int32 Atk, int32 Def);

protected:

	// ���x���A�b�v����
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

private:

	// AnimInstance�̃N���X�p�X
	static const TCHAR *AnimInstanceClassPath;

	// �ړ��pComponent
	UPROPERTY()
	UFloatingPawnMovement *pMovementComponent;

	// �X�e�[�^�X
	PlayerStatus Status;

};
