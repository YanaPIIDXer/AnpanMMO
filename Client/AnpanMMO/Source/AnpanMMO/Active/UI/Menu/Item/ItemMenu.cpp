// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "ItemMenu.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"
#include "MMOGameInstance.h"
#include "Packet/PacketItemUse.h"
#include "Packet/PacketItemSubtractRequest.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketSaveItemShortcutRequest.h"

// �R���X�g���N�^
UItemMenu::UItemMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ������.
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
		if (ItemData.ItemId < 10000)
		{
			const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemData.ItemId);
			check(pItem != nullptr);
			ItemData.Name = pItem->Name;
			ItemData.bIsUsable = (pItem->Type == ItemItem::CONSUME);
		}
		else
		{
			const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().Get(ItemData.ItemId);
			check(pItem != nullptr);
			ItemData.Name = pItem->Name;
			ItemData.bIsUsable = false;
		}
		ItemData.Count = pCharacter->GetStatus().GetItemList().GetCount(ItemData.ItemId);
		Items.Add(ItemData);
	}

	const TArray<uint32> &ItemShortcuts = pCharacter->GetStatus().GetItemList().GetItemShortcut();

	FItemData ItemShortcut1, ItemShortcut2;
	ItemShortcut1.ItemId = ItemShortcuts[0];
	const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemShortcuts[0]);
	if (pItem != nullptr)
	{
		ItemShortcut1.Name = pItem->Name;
	}
	ItemShortcut1.Count = pCharacter->GetStatus().GetItemList().GetCount(ItemShortcuts[0]);

	ItemShortcut2.ItemId = ItemShortcuts[1];
	pItem = MasterData::GetInstance().GetItemMaster().Get(ItemShortcuts[1]);
	if (pItem != nullptr)
	{
		ItemShortcut2.Name = pItem->Name;
	}
	ItemShortcut2.Count = pCharacter->GetStatus().GetItemList().GetCount(ItemShortcuts[1]);

	InitEvent(Items, ItemShortcut1, ItemShortcut2);
}

// �p�P�b�g����M�����B
void UItemMenu::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case PacketID::ItemSubtract:

			// �A�C�e���������č\�z.
			Init();
			break;
	}
}


// �g�p.
void UItemMenu::Use(const FItemData &Data)
{
	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pCharacter != nullptr);

	// ���j���[�o�R�̏ꍇ�͎������g��ΏۂɎg�p����B
	PacketItemUse Packet(Data.ItemId, CharacterType::Player, pCharacter->GetUuid());

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}

// �j��.
void UItemMenu::Subtract(const FItemData &Data, int32 Count)
{
	PacketItemSubtractRequest Packet(Data.ItemId, Count);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}

// �V���[�g�J�b�g�ۑ�.
void UItemMenu::SaveShortcut(const FItemData &Data1, const FItemData &Data2)
{
	PacketSaveItemShortcutRequest Packet(Data1.ItemId, Data2.ItemId);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}
