// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ItemMenu.generated.h"

// アイテムデータ
USTRUCT(BlueprintType)
struct FItemData
{

	GENERATED_USTRUCT_BODY()

public:

	// アイテムＩＤ
	uint32 ItemId;

	// 名前.
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	// 個数.
	UPROPERTY(BlueprintReadOnly)
	int32 Count;

};

/**
 * アイテムメニュー
 */
UCLASS()
class ANPANMMO_API UItemMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UItemMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UItemMenu() {}

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void Init();

protected:

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "ItemMenu")
	void InitEvent(const TArray<FItemData> &Items);
	void InitEvent_Implementation(const TArray<FItemData> &Items) {}

};
