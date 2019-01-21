// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Buff/BuffManager.h"
#include "Master/BuffMaster.h"
#include "CharacterBase.generated.h"

// �L�����N�^�^�C�v
UENUM(BlueprintType, Category = "Character")
enum class ECharacterType : uint8
{
	None UMETA(Hidden),

	// ����
	Player,

	// ���l.
	Other,

	// �A���p��.
	Anpan,

	// NPC
	NPC,
};

class ATargetCircle;
class ASkillRangeDecal;

/**
 * �L�����N�^���N���X
 */
UCLASS()
class ANPANMMO_API ACharacterBase : public ACharacter
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	ACharacterBase(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ACharacterBase() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// �j�����ꂽ.
	UFUNCTION()
	void OnDestroy(AActor *pDestroyedActor);

	// �_���[�W��^����B
	void ApplyDamage(int32 Value);

	// ��.
	void Heal(int32 Value);

	// ����ł�H
	bool IsDead() const { return (Hp <= 0); }

	// HP�擾
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetHp() const { return Hp; }

	// �ő�HP�擾.
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetMaxHp() const { return MaxHp; }

	// �����̔������擾.
	virtual float GetHalfHeight() const { return 0.0f; }
	
	// �L�����N�^�^�C�v���擾.
	UFUNCTION(BlueprintPure, Category = "Character")
	virtual ECharacterType GetCharacterType() const { return ECharacterType::None; }

	// �^�[�Q�b�g�T�[�N���𐶐�.
	void SpawnTargetCircle();

	// �^�[�Q�b�g�T�[�N����P��.
	void DestroyTargetCircle();

	// UUID���擾.
	//virtual uint32 GetUuid() const = 0;
	virtual uint32 GetUuid() const { return 0; }

	// �L�����N�^�����擾.
	//virtual FString GetCharacterName() const = 0;
	UFUNCTION(BlueprintPure, Category = "Character")
	virtual FString GetCharacterName() const { return ""; }

	// �X�L���L���X�g����M�����B
	virtual void OnSkillCast(uint32 SkillId);

	// �X�L���L���X�g�����������B
	virtual void OnSkillCastFinished();

	// �X�L����������M�����B
	virtual void OnSkillActivate() {}

	// �o�t�ǉ�.
	void AddBuff(uint32 BuffId);

	// �o�t����.
	void RemoveBuff(uint8 Type);

	// ��჏�Ԃ��H
	UFUNCTION(BlueprintPure, Category = "Character")
	bool IsParalysis() const { return BuffMgr.IsActive(BuffItem::PARALYSIS); }

	// �ړ����x���[�g��ݒ�.
	void SetMoveSpeedRate(float Rate);

protected:

	// ������.
	void Initialize(int32 InHp, int32 InMaxHp);

	// �ő�HP���X�V.
	void UpdateMaxHp(int32 InMaxHp) { MaxHp = InMaxHp; }

	// �_���[�W�C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnDamaged(int32 BeforeHp, int32 AfterHp, int32 DamageValue);
	virtual void OnDamaged_Implementation(int32 BeforeHp, int32 AfterHp, int32 DamageValue) {}

	// �񕜃C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnHeal(int32 BeforeHp, int32 AfterHp, int32 HealValue);
	void OnHeal_Implementation(int32 BeforeHp, int32 AfterHp, int32 HealValue) {}

	// ���S�C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnDead();
	virtual void OnDead_Implementation() {}

	// HP��ݒ�.
	void SetHP(int InHp) { Hp = InHp; }

	// �o�t���ǉ����ꂽ�B
	virtual void OnAddedBuff(uint32 BuffId) {}

	// �o�t�����ł����B
	virtual void OnRemovedBuff(uint8 Type) {}

private:

	// ��b�ړ����x.
	static const float BaseMoveSpeed;

	// HP
	int32 Hp;

	// �ő�HP
	int32 MaxHp;

	// �^�[�Q�b�g�T�[�N��
	UPROPERTY()
	ATargetCircle *pTargetCircle;

	// �X�L���͈̔̓f�J�[��
	UPROPERTY()
	ASkillRangeDecal *pSkillRangeDecal;

	// �o�t�Ǘ�.
	BuffManager BuffMgr;
	

	// �X�L���͈̔̓f�J�[����j��.
	void DestroySkillRangeDecal();

};
