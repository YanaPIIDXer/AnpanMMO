// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Input/Reply.h"
#include "JoyStick.generated.h"

struct FGeometry;
struct FPointerEvent;

/**
 * ジョイスティック
 */
UCLASS()
class ANPANMMO_API UJoyStick : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UJoyStick(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UJoyStick() {}

	// タッチ開始.
	virtual FReply NativeOnTouchStarted(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent) override;

	// タッチ移動.
	virtual FReply NativeOnTouchMoved(const FGeometry &InGeometry, const FPointerEvent &InGestureEvent) override;

	// タッチ終了.
	virtual FReply NativeOnTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent) override;
	
protected:



private:
	
	
};
