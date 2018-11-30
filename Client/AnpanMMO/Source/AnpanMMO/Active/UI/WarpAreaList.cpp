// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpAreaList.h"
#include "Util.h"
#include "Master/MasterData.h"
#include "Character/Player/GameController.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketAreaMoveRequest.h"

const TCHAR *UWarpAreaList::AssetPath = TEXT("/Game/Blueprints/UI/Active/WarpAreaList.WarpAreaList");

// ����.
void UWarpAreaList::Create(UObject *pOuter, uint32 Id)
{
	UWarpAreaList *pList = Util::LoadBlueprint<UWarpAreaList>(pOuter, AssetPath);
	check(pList != nullptr);
	pList->Id = Id;
	pList->Show();
}

// �R���X�g���N�^
UWarpAreaList::UWarpAreaList(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �������̏���.
void UWarpAreaList::NativeConstruct()
{
	Super::NativeConstruct();

	auto AllList = MasterData::GetInstance().GetWarpDataMaster().GetAll();
	TArray<WarpDataItem> ItemList;
	for (const auto &Item : AllList)
	{
		if (Item.WarpDataId == Id)
		{
			ItemList.Add(Item);
		}
	}

	for (const auto &Item : ItemList)
	{
		const auto *pAreaData = MasterData::GetInstance().GetAreaMaster().Get(Item.AreaId);
		check(pAreaData != nullptr);
		AddItem(Item.ID, Item.AreaId, pAreaData->Name);
	}
}


// �G���A�ړ��p�P�b�g���M.
void UWarpAreaList::SendAreaMoveRequest(int32 MoveId, int32 AreaId)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SetAreaIdCache(AreaId);

	PacketAreaMoveRequest Packet(MoveId);
	pInst->SendPacket(&Packet);
}
