// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NPCCharacter.h"
#include "Master/MasterData.h"
#include "DLC/PakFileManager.h"
#include "DLC/DataAsset/NPCDataAsset.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"
#include "Active/ActiveGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Config.h"
#include "Packet/PacketNPCTalk.h"

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

	FString DLCPath = Config::GetDLCDirectory() + "\\" + pResourceItem->DLCName + ".pak";
	PakFileManager::GetInstance().Mount(DLCPath);

	FString AssetPath = "/" + pResourceItem->DLCName + "/Assets.Assets";

	UNPCDataAsset *pDataAsset = LoadObject<UNPCDataAsset>(pChara, *AssetPath, *AssetPath);
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

// 話しかける
void ANPCCharacter::Talk()
{
	const NPCItem *pItem = MasterData::GetInstance().GetNPCMaster().Get(Id);
	check(pItem != nullptr);

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketNPCTalk Packet(Id);
	pInst->SendPacket(&Packet);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	pGameMode->StartScript(pItem->ScriptName);
}


// メッシュのセットアップ
void ANPCCharacter::SetupMesh(USkeletalMesh *pMesh)
{
	GetMesh()->SetSkeletalMesh(pMesh);
	// @HACK:超適当。
	HalfHeight = pMesh->GetBounds().SphereRadius * 0.1f;
}
