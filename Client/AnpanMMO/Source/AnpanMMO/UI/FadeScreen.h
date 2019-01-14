// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FadeScreen.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFadeFinished);

// �t�F�[�h���[�h
UENUM(Blueprintable, Category = "Fade")
enum class EFadeMode : uint8
{
	// �Ȃ�
	None UMETA(Hidden),

	// �t�F�[�h�C��
	FadeIn,

	// �t�F�[�h�A�E�g
	FadeOut,
};

/**
 * ��ʂ̃t�F�[�h
 */
UCLASS()
class ANPANMMO_API UFadeScreen : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UFadeScreen(const FObjectInitializer &ObjectInitializer);
	
	// �f�X�g���N�^
	virtual ~UFadeScreen() {}

	// ���t���[���̏���.
	virtual void NativeTick(const FGeometry &Geometry, float DeltaTime) override;

	// �t�F�[�h�J�n.
	UFUNCTION(BlueprintCallable, Category = "Fade")
	void Start(EFadeMode Mode);

	// �A���t�@�l�𒼐ڐݒ�.
	UFUNCTION(BlueprintCallable, Category = "Fade")
	void SetAlpha(float InAlphaValue) { AlphaValue = FMath::Clamp<float>(InAlphaValue, 0.0f, 1.0f); }

	// �t�F�[�h����delegate
	UPROPERTY(BlueprintAssignable, Category = "Fade")
	FOnFadeFinished OnFadeFinished;

protected:

	// �A���t�@�l.
	UPROPERTY(BlueprintReadOnly, Category = "Fade")
	float AlphaValue;

	// �J�n.
	UFUNCTION(BlueprintNativeEvent, Category = "Fade")
	void OnStart();
	void OnStart_Implementation() {}

	// �I��.
	UFUNCTION(BlueprintNativeEvent, Category = "Fade")
	void OnFinish();
	void OnFinish_Implementation() {}

private:

	// �P�b�Ԃ̃A���t�@�l�ϓ���.
	static const float AlphaSpeedBySec;

	// �t�F�[�h���[�h
	EFadeMode FadeMode;
	
};
