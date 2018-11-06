// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "JoyStick.h"
#include "Input/Events.h"

// �R���X�g���N�^
UJoyStick::UJoyStick(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �^�b�`�J�n.
FReply UJoyStick::NativeOnTouchStarted(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent)
{
	return Super::NativeOnTouchStarted(InGeometry, InGestureEvent);
}

// �^�b�`�ړ�.
FReply UJoyStick::NativeOnTouchMoved(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent)
{
	return Super::NativeOnTouchMoved(InGeometry, InGestureEvent);
}

// �^�b�`�I��.
FReply UJoyStick::NativeOnTouchEnded(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent)
{
	return Super::NativeOnTouchEnded(InGeometry, InGestureEvent);
}

