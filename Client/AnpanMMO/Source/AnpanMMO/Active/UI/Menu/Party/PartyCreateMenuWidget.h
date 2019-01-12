// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "PartyCreateMenuWidget.generated.h"

/**
 * パーティ作成メニュー
 */
UCLASS()
class ANPANMMO_API UPartyCreateMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// 生成.
	static UPartyCreateMenuWidget *Create(UObject *pOuter);

	// コンストラクタ
	UPartyCreateMenuWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UPartyCreateMenuWidget() {}

protected:

	// パーティ作成リクエスト送信.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendPartyCreateRequest();
	
private:

	// アセットパス
	static const TCHAR *AssetPath;

};
