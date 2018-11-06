// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttachableWidget.generated.h"

/**
 * Actor�ɒǏ]����Widget
 */
UCLASS()
class ANPANMMO_API UAttachableWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UAttachableWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UAttachableWidget() {}

	// �J�n���̏���.
	virtual void NativeConstruct() override;

	// ���t���[���̏���.
	virtual void NativeTick(const FGeometry &InGeometry, float InDeltaTime) override;

	// �^�[�Q�b�g��ݒ�.
	UFUNCTION(BlueprintCallable, Category = "Attachable")
	void SetTarget(AActor *pInTargetActor) { pTargetActor = pInTargetActor; }

	// �I�t�Z�b�g��ݒ�.
	UFUNCTION(BlueprintCallable, Category = "Attachable")
	void SetOffset(const FVector &InOffset) { Offset = InOffset; }

protected:

	// �\�����.
	UPROPERTY(BlueprintReadOnly, Category = "Attachable")
	ESlateVisibility Visible;

	// �\�����W.
	UPROPERTY(BlueprintReadOnly, Category = "Attachable")
	FVector2D DisplayPosition;

private:

	// �Ώ�Actor
	TWeakObjectPtr<AActor> pTargetActor;

	// �R���g���[��
	TWeakObjectPtr<APlayerController> pController;
	
	// �I�t�Z�b�g.
	FVector Offset;

};
