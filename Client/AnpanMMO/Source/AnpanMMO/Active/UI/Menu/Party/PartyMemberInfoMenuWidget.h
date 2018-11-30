// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "PartyInfoMenuWidget.h"
#include "PartyMemberInfoMenuWidget.generated.h"

/**
 * パーティメンバ情報メニュークラス
 */
UCLASS()
class ANPANMMO_API UPartyMemberInfoMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UPartyMemberInfoMenuWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UPartyMemberInfoMenuWidget() {}

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void Init(bool bInIsLeader, const FPartyMemberData &InData);

protected:

	// リーダーか？
	UPROPERTY(BlueprintReadOnly, Category = "Party")
	bool bIsLeader;

	// データ
	UPROPERTY(BlueprintReadOnly)
	FPartyMemberData Data;


	// キックする
	UFUNCTION(BlueprintCallable, Category = "Party")
	void Kick();

};
