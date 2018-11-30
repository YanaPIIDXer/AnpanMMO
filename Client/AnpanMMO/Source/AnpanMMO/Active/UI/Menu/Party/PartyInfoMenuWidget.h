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

	// 開始時の処理.
	virtual void NativeConstruct() override;

protected:

	// 初期化された
	UFUNCTION(BlueprintNativeEvent, Category = "Party")
	void OnInit();
	void OnInit_Implementation() {}

	// 解散リクエストを送信.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendDissolutionRequest();

	// 離脱リクエストを送信.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendExitRequest();


	// リーダーか？
	UPROPERTY(BlueprintReadOnly, Category = "Party")
	bool bIsLeader;

private:

	// アセットパス
	static const TCHAR *AssetPath;
	
};
