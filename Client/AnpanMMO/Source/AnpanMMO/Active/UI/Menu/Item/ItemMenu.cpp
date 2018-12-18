// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ItemMenu.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"
#include "MMOGameInstance.h"
#include "Packet/PacketItemUse.h"
#include "Packet/PacketItemSubtractRequest.h"
#include "Packet/CharacterType.h"

// コンストラクタ
UItemMenu::UItemMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 初期化.
void UItemMenu::Init()
{
	TArray<FItemData> Items;

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pCharacter != nullptr);

	TArray<uint32> ItemIds = pCharacter->GetStatus().GetItemList().CollectItemList();
	for (int32 i = 0; i < ItemIds.Num(); i++)
	{
		FItemData ItemData;
		ItemData.ItemId = ItemIds[i];
		const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemData.ItemId);
		check(pItem != nullptr);
		ItemData.Name = pItem->Name;
		ItemData.Count = pCharacter->GetStatus().GetItemList().GetCount(ItemData.ItemId);
		Items.Add(ItemData);
	}

	InitEvent(Items);
}

// パケットを受信した。
void UItemMenu::OnRecvPacket(uint8 ID)
{
	switch (ID)
	{
		case PacketID::ItemSubtract:

			// アイテム消費したら再構築.
			Init();
			break;
	}
}


// 使用.
void UItemMenu::Use(const FItemData &Data)
{
	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pCharacter != nullptr);

	// メニュー経由の場合は自分自身を対象に使用する。
	PacketItemUse Packet(Data.ItemId, CharacterType::Player, pCharacter->GetUuid());

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}

// 破棄.
void UItemMenu::Subtract(const FItemData &Data, int32 Count)
{
	PacketItemSubtractRequest Packet(Data.ItemId, Count);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}
