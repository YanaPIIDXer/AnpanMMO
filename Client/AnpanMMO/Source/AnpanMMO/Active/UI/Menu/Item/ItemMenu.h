// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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

	// 使用可能か？
	UPROPERTY(BlueprintReadOnly)
	bool bIsUsable;

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

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID) override;

protected:

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "ItemMenu")
	void InitEvent(const TArray<FItemData> &Items, const FItemData &ItemShortcut1, const FItemData &ItemShortcut2);
	void InitEvent_Implementation(const TArray<FItemData> &Items, const FItemData &ItemShortcut1, const FItemData &ItemShortcut2) {}

	// 使用.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void Use(const FItemData &Data);

	// 破棄.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void Subtract(const FItemData &Data, int32 Count);

	// ショートカット保存.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void SaveShortcut(const FItemData &Data1, const FItemData &Data2);

};
