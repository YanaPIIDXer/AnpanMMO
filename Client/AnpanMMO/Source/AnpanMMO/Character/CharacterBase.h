// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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

	// �_���[�W��^����B
	void ApplyDamage(int32 Value);

	// ����ł�H
	bool IsDead() const { return (Hp <= 0); }

	// HP�擾
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetHp() const { return Hp; }

	// �ő�HP�擾.
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetMaxHp() const { return MaxHp; }

	// �L�����N�^�^�C�v���擾.
	UFUNCTION(BlueprintPure, Category = "Character")
	virtual ECharacterType GetCharacterType() const { return ECharacterType::None; }

protected:

	// ������.
	void Initialize(int32 InHp, int32 InMaxHp);

	// �ő�HP���X�V.
	void UpdateMaxHp(int32 InMaxHp) { MaxHp = InMaxHp; }

	// �_���[�W�C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnDamaged(int32 BeforeHp, int32 AfterHp, int32 DamageValue);
	virtual void OnDamaged_Implementation(int32 BeforeHp, int32 AfterHp, int32 DamageValue) {}

	// ���S�C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnDead();
	virtual void OnDead_Implementation() {}

	// HP��ݒ�.
	void SetHP(int InHp) { Hp = InHp; }

private:

	// HP
	int32 Hp;

	// �ő�HP
	int32 MaxHp;
	
};
