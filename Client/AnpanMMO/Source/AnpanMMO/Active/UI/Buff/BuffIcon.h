// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuffIcon.generated.h"

// �o�t�^�C�v
UENUM(BlueprintType)
enum class EBuffType : uint8
{
	// ����.
	Invalid,

	// �X�s�[�h�A�b�v
	SpeedUp,

	// ������.
	AutoHeal,

	// ��.
	Poision,

	// ���.
	Paralysis,
};

/**
 * �o�t�A�C�R��
 */
UCLASS()
class ANPANMMO_API UBuffIcon : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UBuffIcon(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UBuffIcon() {}

	// �Z�b�g�A�b�v
	UFUNCTION(BlueprintCallable, Category = "BuffIcon")
	void Setup(EBuffType InType, float Time);

	// ���t���[���̏���.
	virtual void NativeTick(const FGeometry &InGeometry, float InDeltaTime) override;

	// �^�C�v���擾.
	UFUNCTION(BlueprintPure, Category = "BuffIcon")
	EBuffType GetType() const { return Type; }

	// �o�t���H
	UFUNCTION(BlueprintPure, Category = "BuffIcon")
	bool IsBuff() const;

protected:

	// �Z�b�g�A�b�v���̃C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "BuffIcon")
	void OnSetup();
	void OnSetup_Implementation() {}

	// �c�莞�Ԃ̃p�[�Z���e�[�W���擾.
	UFUNCTION(BlueprintPure, Category = "BuffIcon")
	float GetLastTimePercentage() const { return (LastTime / BuffTime); }

private:

	// �^�C�v
	EBuffType Type;

	// �o�t�p������.
	float BuffTime;
	
	// �c�莞��.
	float LastTime;

};
