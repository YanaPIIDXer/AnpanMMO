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

// ����.
UScriptShopWidget *UScriptShopWidget::Create(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UScriptShopWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// �R���X�g���N�^
UScriptShopWidget::UScriptShopWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, ShopId(0)
	, CurrentGold(0)
{
}

// �p�P�b�g����M�����B
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


// ������.
void UScriptShopWidget::Init()
{
	AGameCharacter *pChara = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pChara != nullptr);

	CurrentGold = pChara->GetGold();

	// �V���b�v�Ŕ����Ă���A�C�e��
	TArray<FShopItem> ShopItems;
	TArray<const ShopItem *> Items = MasterData::GetInstance().GetShopMaster().CollectItems(ShopId);
	for (const auto *pShopItem : Items)
	{
		FShopItem ShopItem = GenerateShopItem(pShopItem->ItemId, true);
		ShopItems.Add(ShopItem);
	}

	// �����A�C�e��
	TArray<FShopItem> SellItems;
	TArray<uint32> ItemList = pChara->GetStatus().GetItemList().CollectItemList();
	for (uint32 ItemId : ItemList)
	{
		FShopItem SellItem = GenerateShopItem(ItemId, false);
		SellItems.Add(SellItem);
	}

	OnInit(ShopItems, SellItems);
}

// �A�C�e�����������擾.
int32 UScriptShopWidget::GetHaveItemCount(const FShopItem &Item) const
{
	AGameCharacter *pChara = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pChara != nullptr);

	return pChara->GetItemCount(Item.ItemId);
}

// ���֐i�ށB
void UScriptShopWidget::ToNext()
{
	// �I���p�P�b�g���M�B
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketExitShop Packet;
	pInst->SendPacket(&Packet);

	// �X�N���v�g��Resume
	pInst->GetScript()->Resume();
}

// �w���p�P�b�g�𑗐M.
void UScriptShopWidget::SendBuy(const FShopItem &Item, int32 Count)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketBuyItemRequest Packet(ShopId, Item.ItemId, Count);
	pInst->SendPacket(&Packet);
}

// ���p�p�P�b�g�𑗐M�B
void UScriptShopWidget::SendSell(const FShopItem &Item, int32 Count)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketSellItemRequest Packet(ShopId, Item.ItemId, Count);
	pInst->SendPacket(&Packet);
}


// ShopItem�𐶐�.
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

// ShopItem�𐶐�.
FShopItem UScriptShopWidget::GenerateShopItem(const ItemItem *pItem, bool bBuy)
{
	FShopItem Item;
	Item.ItemId = pItem->ID;
	Item.Name = pItem->Name;
	Item.Gold = (bBuy ? pItem->BuyGold : pItem->SellGold);
	return Item;
}

// ShopItem�𐶐�.
FShopItem UScriptShopWidget::GenerateShopItem(const EquipItem *pItem, bool bBuy)
{
	FShopItem Item;
	Item.ItemId = pItem->ID;
	Item.Name = pItem->Name;
	Item.Gold = (bBuy ? pItem->BuyGold : pItem->SellGold);
	return Item;
}
