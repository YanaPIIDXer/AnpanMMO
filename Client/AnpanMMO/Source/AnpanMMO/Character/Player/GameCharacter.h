// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"
#include "PlayerStatus.h"
#include "PlayerMove.h"
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

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �X�e�[�^�X�擾.
	const PlayerStatus &GetStatus() const { return Status; }

	// �o���l����M�����B
	void OnRecvExp(int32 Exp);

	// ���x���A�b�v����M�����B
	void OnRecvLevelUp(int32 MaxHp, int32 Atk, int32 Def);

	// �ړ��x�N�g���̎擾.
	virtual FVector GetMoveVector() const override;

	// UUID���擾.
	virtual uint32 GetUuid() const override { return Status.GetUuid(); }

	// �L�����N�^�����擾.
	virtual FString GetCharacterName() const override { return Status.GetName(); }
	
	// �L�����N�^�^�C�v���擾.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::Player; }

	// �X�L�����g�p�\���H
	UFUNCTION(BlueprintPure, Category = "Skill")
	bool IsSkillUsable(int32 SkillId) const;

	// �X�L���g�p.
	UFUNCTION(BlueprintCallable, Category = "Skill")
	void UseSkill(int32 SkillId);

protected:

	// ���x���A�b�v����
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

	// ���X�|�������B
	virtual void OnRespawn() override;

private:

	// �X�e�[�^�X
	PlayerStatus Status;

	// �ړ��p�P�b�g����.
	PlayerMove Move;

};
