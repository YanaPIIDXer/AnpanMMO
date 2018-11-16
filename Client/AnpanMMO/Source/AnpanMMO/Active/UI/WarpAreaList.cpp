// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpAreaList.h"
#include "Util.h"
#include "Master/MasterData.h"
#include "Character/Player/GameController.h"
#include "Kismet/GameplayStatics.h"

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

	auto ItemList = MasterData::GetInstance().GetWarpDataMaster().CollectItems(Id);
	for (const auto *pItem : ItemList)
	{
		const auto *pAreaData = MasterData::GetInstance().GetAreaMaster().Get(pItem->AreaId);
		check(pAreaData != nullptr);
		FString AreaName = UTF8_TO_TCHAR(pAreaData->Name.c_str());
		AddItem(pItem->AreaId, AreaName);
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
	UE_LOG(LogTemp, Log, TEXT("SendAreaMoveRequest Id:%d"), Id);
}
