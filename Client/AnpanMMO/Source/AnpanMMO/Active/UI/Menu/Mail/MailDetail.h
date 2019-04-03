// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "MailMenu.h"
#include "MailDetail.generated.h"

/**
 * メール詳細.
 */
UCLASS()
class ANPANMMO_API UMailDetail : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
		
public:

	// コンストラクタ
	UMailDetail(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UMailDetail() {}

	// メールを開く
	UFUNCTION(BlueprintCallable, Category = "Mail")
	void Open(const FMailData &InData);

protected:

	// メールを開いた
	UFUNCTION(BlueprintNativeEvent, Category = "Mail")
	void OnOpen();
	void OnOpen_Implementation() {}

	// データを取得.
	UFUNCTION(BlueprintPure, Category = "Mail")
	const FMailData &GetData() const { return Data; }

private:
	
	// データ
	FMailData Data;

};
