// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterNameInputWidget.generated.h"

/**
 * キャラクタ名入力Widget
 */
UCLASS()
class ANPANMMO_API UCharacterNameInputWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// 表示.
	static UCharacterNameInputWidget *Show(UObject *pOuter, int32 ZOrder);

	// コンストラクタ
	UCharacterNameInputWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UCharacterNameInputWidget() {}

protected:

	// リクエストパケット送信.
	UFUNCTION(BlueprintCallable, Category = "Request")
	void SendRequestPacket(const FString &Name);

private:

	// アセットパス
	static const TCHAR *AssetPath;

};
