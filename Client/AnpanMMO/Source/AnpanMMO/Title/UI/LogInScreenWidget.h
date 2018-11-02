// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LogInScreenWidget.generated.h"

/**
 * ログイン画面Widget
 */
UCLASS()
class ANPANMMO_API ULogInScreenWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	ULogInScreenWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ULogInScreenWidget() {}

protected:
	
	// ログインパケットを送信.
	UFUNCTION(BlueprintCallable, Category = "Connection")
	void SendLogInPacket(const FString &UserName, const FString &Password);
	
};
