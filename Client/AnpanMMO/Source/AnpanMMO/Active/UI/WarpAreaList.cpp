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
	pList->AddToViewport();
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

	auto *pController = Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));
	check(pController != nullptr);
	pController->SetEnableMove(false);

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
		AddItem(Item.ID, pAreaData->Name);
	}
}

// �j�����̏���.
void UWarpAreaList::NativeDestruct()
{
	Super::NativeDestruct();

	auto *pController = Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));
	if (pController == nullptr) { return; }		// check����ƊJ�����ςȂ��ŗ��Ƃ������ɃN���b�V������B
	pController->SetEnableMove(true);
}


// �G���A�ړ��p�P�b�g���M.
void UWarpAreaList::SendAreaMoveRequest(int32 Id)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketAreaMoveRequest Packet(Id);
	pInst->SendPacket(&Packet);
}
