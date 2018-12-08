// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NPCCharacter.h"
#include "Master/MasterData.h"
#include "DLC/PakFileManager.h"
#include "DLC/DataAsset/NPCDataAsset.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"

// Spawn
ANPCCharacter *ANPCCharacter::Spawn(UWorld *pWorld, const NPCItem *pItem)
{
	FVector Pos(pItem->X, pItem->Y, pItem->Z);
	FRotator Rot(0.0f, pItem->Rotation, 0.0f);
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ANPCCharacter *pChara = pWorld->SpawnActor<ANPCCharacter>(Pos, Rot, Param);
	check(pChara != nullptr);

	pChara->Id = pItem->ID;

	const NPCResourceItem *pResourceItem = MasterData::GetInstance().GetNPCReseourceMaster().Get(pItem->ResourceId);
	check(pResourceItem != nullptr);

	FString DLCPath = "/" + pResourceItem->DLCName + "/Assets.Assets";
	PakFileManager::GetInstance().Mount(DLCPath);

	UNPCDataAsset *pDataAsset = LoadObject<UNPCDataAsset>(pChara, *DLCPath, *DLCPath);
	check(pDataAsset != nullptr);

	USkeletalMesh *pMesh = pDataAsset->Get(pResourceItem->Index);
	check(pMesh != nullptr);
	pChara->SetupMesh(pMesh);

	return pChara;
}

// コンストラクタ
ANPCCharacter::ANPCCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, HalfHeight(0.0f)
{
}


// メッシュのセットアップ
void ANPCCharacter::SetupMesh(USkeletalMesh *pMesh)
{
	GetMesh()->SetSkeletalMesh(pMesh);
	HalfHeight = pMesh->GetBounds().BoxExtent.GetMax() - pMesh->GetBounds().BoxExtent.GetMin();
	HalfHeight *= 0.5f;
}
