// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "ScriptShopWidget.h"
#include "Util.h"
#include "Master/MasterData.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/GameCharacter.h"
#include "MMOGameInstance.h"
#include "Packet/PacketExitShop.h"
#include "Packet/PacketBuyItemRequest.h"
#include "Packet/PacketSellItemRequest.h"

const TCHAR *UScriptShopWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Script/ShopWidget.ShopWidget");

// 生成.
UScriptShopWidget *UScriptShopWidget::Create(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UScriptShopWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// コンストラクタ
UScriptShopWidget::UScriptShopWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, ShopId(0)
	, CurrentGold(0)
{
}

// パケットを受信した。
void UScriptShopWidget::OnRecvPacket(uint8 ID)
{
	switch (ID)
	{
		case PacketID::BuyItemResult:
		case PacketID::SellItemResult:
			
			Init();
			break;
	}
}


// 初期化.
void UScriptShopWidget::Init()
{
	AGameCharacter *pChara = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pChara != nullptr);

	CurrentGold = pChara->GetGold();

	// ショップで売っているアイテム
	TArray<FShopItem> ShopItems;
	TArray<const ShopItem *> Items = MasterData::GetInstance().GetShopMaster().CollectItems(ShopId);
	for (const auto *pShopItem : Items)
	{
		FShopItem ShopItem = GenerateShopItem(pShopItem->ItemId, true);
		ShopItems.Add(ShopItem);
	}

	// 所持アイテム
	TArray<FShopItem> SellItems;
	TArray<uint32> ItemList = pChara->GetStatus().GetItemList().CollectItemList();
	for (uint32 ItemId : ItemList)
	{
		FShopItem SellItem = GenerateShopItem(ItemId, false);
		SellItems.Add(SellItem);
	}

	OnInit(ShopItems, SellItems);
}

// アイテム所持数を取得.
int32 UScriptShopWidget::GetHaveItemCount(const FShopItem &Item) const
{
	AGameCharacter *pChara = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pChara != nullptr);

	return pChara->GetItemCount(Item.ItemId);
}

// 次へ進む。
void UScriptShopWidget::ToNext()
{
	// 終了パケット送信。
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketExitShop Packet;
	pInst->SendPacket(&Packet);

	// スクリプトのResume
	pInst->GetScript()->Resume();
}

// 購入パケットを送信.
void UScriptShopWidget::SendBuy(const FShopItem &Item, int32 Count)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketBuyItemRequest Packet(ShopId, Item.ItemId, Count);
	pInst->SendPacket(&Packet);
}

// 売却パケットを送信。
void UScriptShopWidget::SendSell(const FShopItem &Item, int32 Count)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketSellItemRequest Packet(ShopId, Item.ItemId, Count);
	pInst->SendPacket(&Packet);
}


// ShopItemを生成.
FShopItem UScriptShopWidget::GenerateShopItem(uint32 ItemId, bool bBuy)
{
	FShopItem ShopItem;
	if (ItemId < 10000)
	{
		const ItemItem *pItemItem = MasterData::GetInstance().GetItemMaster().Get(ItemId);
		ShopItem = GenerateShopItem(pItemItem, bBuy);
	}
	else
	{
		const EquipItem *pEquipItem = MasterData::GetInstance().GetEquipMaster().Get(ItemId);
		ShopItem = GenerateShopItem(pEquipItem, bBuy);
	}
	return ShopItem;
}

// ShopItemを生成.
FShopItem UScriptShopWidget::GenerateShopItem(const ItemItem *pItem, bool bBuy)
{
	FShopItem Item;
	Item.ItemId = pItem->ID;
	Item.Name = pItem->Name;
	Item.Gold = (bBuy ? pItem->BuyGold : pItem->SellGold);
	return Item;
}

// ShopItemを生成.
FShopItem UScriptShopWidget::GenerateShopItem(const EquipItem *pItem, bool bBuy)
{
	FShopItem Item;
	Item.ItemId = pItem->ID;
	Item.Name = pItem->Name;
	Item.Gold = (bBuy ? pItem->BuyGold : pItem->SellGold);
	return Item;
}
