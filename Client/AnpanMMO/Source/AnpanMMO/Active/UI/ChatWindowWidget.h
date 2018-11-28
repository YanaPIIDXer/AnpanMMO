// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChatWindowWidget.generated.h"

// チャットの種類.
UENUM(BlueprintType, Category = "Chat")
enum class EChatType : uint8
{
	Say,
	Showt,
};

/**
 * チャットウィンドウ
 */
UCLASS()
class ANPANMMO_API UChatWindowWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UChatWindowWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UChatWindowWidget() {}

protected:
	
	// チャット送信.
	UFUNCTION(BlueprintCallable, Category = "Chat")
	void SendChat(EChatType Type, const FString &Message);

};
