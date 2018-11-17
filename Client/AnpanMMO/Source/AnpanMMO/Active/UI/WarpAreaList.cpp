// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpAreaList.h"
#include "Util.h"
#include "Master/MasterData.h"
#include "Character/Player/GameController.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketAreaMoveRequest.h"

const TCHAR *UWarpAreaList::AssetPath = TEXT("/Game/Blueprints/UI/Active/WarpAreaList.WarpAreaList");

// 生成.
void UWarpAreaList::Create(UObject *pOuter, uint32 Id)
{
	UWarpAreaList *pList = Util::LoadBlueprint<UWarpAreaList>(pOuter, AssetPath);
	check(pList != nullptr);
	pList->Id = Id;
	pList->AddToViewport();
}

// コンストラクタ
UWarpAreaList::UWarpAreaList(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 生成時の処理.
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

// 破棄時の処理.
void UWarpAreaList::NativeDestruct()
{
	Super::NativeDestruct();

	auto *pController = Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));
	if (pController == nullptr) { return; }		// checkすると開きっぱなしで落とした時にクラッシュする。
	pController->SetEnableMove(true);
}


// エリア移動パケット送信.
void UWarpAreaList::SendAreaMoveRequest(int32 Id)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketAreaMoveRequest Packet(Id);
	pInst->SendPacket(&Packet);
}
