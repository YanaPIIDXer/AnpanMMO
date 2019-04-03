// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptShopWidget.generated.h"

// ショップアイテム
// ※購入・売却の両方を兼ねる。
USTRUCT(BlueprintType)
struct FShopItem
{

	GENERATED_USTRUCT_BODY()

public:

	// アイテムＩＤ
	uint32 ItemId;

	// 名前.
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	// 購入 or 売却価格.
	UPROPERTY(BlueprintReadOnly)
	int32 Gold;

};

struct ItemItem;
struct EquipItem;

/**
 * スクリプト：ショップ画面.
 */
UCLASS()
class ANPANMMO_API UScriptShopWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// 生成.
	static UScriptShopWidget *Create(UObject *pOuter);

	// コンストラクタ
	UScriptShopWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UScriptShopWidget() {}

	// ショップＩＤを設定.
	void SetShopId(uint32 InShopId) { ShopId = InShopId; }

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void Init();

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "Shop")
	void OnInit(const TArray<FShopItem> &ShopItems, const TArray<FShopItem> &SellItems);
	void OnInit_Implementation(const TArray<FShopItem> &ShopItems, const TArray<FShopItem> &SellItems) {}

	// アイテム所持数を取得.
	UFUNCTION(BlueprintPure, Category = "Shop")
	int32 GetHaveItemCount(const FShopItem &Item) const;

	// 次へ進む。
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void ToNext();

	// 現在のゴールドを取得.
	UFUNCTION(BlueprintPure, Category = "Shop")
	int32 GetCurrentGold() const { return CurrentGold; }

	// 購入パケットを送信.
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void SendBuy(const FShopItem &Item, int32 Count);

	// 売却パケットを送信.
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void SendSell(const FShopItem &Item, int32 Count);

private:

	// アセットのパス
	static const TCHAR *AssetPath;

	// ショップＩＤ
	uint32 ShopId;

	// 現在のゴールド
	int32 CurrentGold;


	// ShopItemを生成.
	FShopItem GenerateShopItem(uint32 ItemId, bool bBuy);
	FShopItem GenerateShopItem(const ItemItem *pItem, bool bBuy);
	FShopItem GenerateShopItem(const EquipItem *pItem, bool bBuy);

};
