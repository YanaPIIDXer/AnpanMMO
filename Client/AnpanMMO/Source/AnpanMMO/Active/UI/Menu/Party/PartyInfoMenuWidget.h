// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "PartyInfoMenuWidget.generated.h"

/**
 * パーティ情報メニューWidget
 */
UCLASS()
class ANPANMMO_API UPartyInfoMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// 生成.
	static UPartyInfoMenuWidget *Create(UObject *pOuter);

	// コンストラクタ
	UPartyInfoMenuWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UPartyInfoMenuWidget() {}

protected:

	// 解散リクエストを送信.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendDissolutionRequest();

private:

	// アセットパス
	static const TCHAR *AssetPath;
	
};
