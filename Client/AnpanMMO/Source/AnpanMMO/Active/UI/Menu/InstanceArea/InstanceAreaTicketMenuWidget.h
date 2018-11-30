// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "InstanceAreaTicketMenuWidget.generated.h"

/**
 * インスタンスマップチケットメニュー
 */
UCLASS()
class ANPANMMO_API UInstanceAreaTicketMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// 表示.
	static void ShowWidget(UObject *pOuter, uint32 TicketId);

	// コンストラクタ
	UInstanceAreaTicketMenuWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UInstanceAreaTicketMenuWidget() {}

protected:

	// 参加を送信。
	UFUNCTION(BlueprintCallable, Category = "InstanceAreaTicket")
	void SendEnter();

	// 破棄を送信.
	UFUNCTION(BlueprintCallable, Category = "InstanceAreaTicket")
	void SendDiscard();

private:

	// アセットパス
	static const TCHAR *AssetPath;

	// チケットＩＤ
	uint32 TicketId;
	
};
