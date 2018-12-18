// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ItemMenu.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"

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
