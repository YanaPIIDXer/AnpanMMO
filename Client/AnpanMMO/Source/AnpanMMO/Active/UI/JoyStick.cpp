// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "JoyStick.h"
#include "Input/Events.h"

// コンストラクタ
UJoyStick::UJoyStick(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// タッチ開始.
FReply UJoyStick::NativeOnTouchStarted(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent)
{
	return Super::NativeOnTouchStarted(InGeometry, InGestureEvent);
}

// タッチ移動.
FReply UJoyStick::NativeOnTouchMoved(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent)
{
	return Super::NativeOnTouchMoved(InGeometry, InGestureEvent);
}

// タッチ終了.
FReply UJoyStick::NativeOnTouchEnded(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent)
{
	return Super::NativeOnTouchEnded(InGeometry, InGestureEvent);
}

