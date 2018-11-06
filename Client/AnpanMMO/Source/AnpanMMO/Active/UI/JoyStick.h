// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Input/Reply.h"
#include "JoyStick.generated.h"

struct FGeometry;
struct FPointerEvent;

/**
 * �W���C�X�e�B�b�N
 */
UCLASS()
class ANPANMMO_API UJoyStick : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UJoyStick(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UJoyStick() {}

	// �^�b�`�J�n.
	virtual FReply NativeOnTouchStarted(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent) override;

	// �^�b�`�ړ�.
	virtual FReply NativeOnTouchMoved(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent) override;

	// �^�b�`�I��.
	virtual FReply NativeOnTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent) override;
	
protected:



private:
	
	
};
