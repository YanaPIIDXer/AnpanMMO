// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpAreaList.h"
#include "Util.h"
#include "Master/MasterData.h"
#include "Character/Player/GameController.h"
#include "Kismet/GameplayStatics.h"

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

	auto ItemList = MasterData::GetInstance().GetWarpDataMaster().CollectItems(Id);
	for (const auto *pItem : ItemList)
	{
		const auto *pAreaData = MasterData::GetInstance().GetAreaMaster().Get(pItem->AreaId);
		check(pAreaData != nullptr);
		FString AreaName = UTF8_TO_TCHAR(pAreaData->Name.c_str());
		AddItem(pItem->AreaId, AreaName);
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
	UE_LOG(LogTemp, Log, TEXT("SendAreaMoveRequest Id:%d"), Id);
}
