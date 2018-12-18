// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ItemMenu.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"
#include "MMOGameInstance.h"
#include "Packet/PacketItemUse.h"
#include "Packet/PacketItemSubtractRequest.h"
#include "Packet/CharacterType.h"

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
		const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemData.ItemId);
		check(pItem != nullptr);
		ItemData.Name = pItem->Name;
		ItemData.Count = pCharacter->GetStatus().GetItemList().GetCount(ItemData.ItemId);
		Items.Add(ItemData);
	}

	InitEvent(Items);
}

// �p�P�b�g����M�����B
void UItemMenu::OnRecvPacket(uint8 ID)
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
