// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Character/CharacterBase.h"
#include "SkillRangeDecal.generated.h"

class UDecalComponent;
class UMaterialInstanceDynamic;

/**
 * �X�L���͈͕̔\���f�J�[��
 */
UCLASS()
class ANPANMMO_API ASkillRangeDecal : public AActor
{

	GENERATED_BODY()
	
public:	
	
	// Spawn
	static ASkillRangeDecal *Spawn(UWorld *pWorld, const FVector &CharacterPos, const FRotator &CharacterRot, ECharacterType CharacterType, uint32 SkillId);

	// �R���X�g���N�^
	ASkillRangeDecal(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ASkillRangeDecal() {}

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

private:

	// �~�`�}�e���A���p�X
	static const TCHAR *CircleMaterialPath;

	// ��`�}�e���A���p�X
	static const TCHAR *BoxMaterialPath;

	// �F�p�����[�^��.
	static const FName ColorParamName;

	// ���p�����[�^��.
	static const FName AlphaParamName;

	// �U���X�L���̐F.
	static const FLinearColor AttackColor;

	// �񕜃X�L���̐F.
	static const FLinearColor HealColor;

	// �G�̍U���X�L���̐F.
	static const FLinearColor EnemyAttackColor;

	// �G�̉񕜃X�L���̐F.
	static const FLinearColor EnemyHealColor;

	// �X�P�[�����O�ɂ����鎞��.
	static const float ScaleAnimationTime;

	// DecalComponent
	UPROPERTY()
	UDecalComponent *pDecalComponent;

	// �}�e���A��
	UPROPERTY()
	UMaterialInstanceDynamic *pMaterial;

	// �F.
	FLinearColor Color;

	// ���݂̕�.
	float CurrentWidth;

	// ���݂̍���.
	float CurrentHeight;

	// �f�J�[���̕�
	float DecalWidth;

	// �f�J�[���̍���
	float DecalHeight;

	// �o�ߎ���.
	float ElapsedTime;

	// ���l.
	float Alpha;


	// �Z�b�g�A�b�v
	void Setup(ECharacterType CharacterType, uint32 SkillId);

};
