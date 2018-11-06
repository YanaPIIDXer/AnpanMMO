// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Anpan.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Util.h"
#include "Packet/AnpanData.h"

const TCHAR *AAnpan::MeshPath = TEXT("/Game/Meshes/Anpan/Mesh/Anpan.Anpan");
const TCHAR *AAnpan::BlueprintPath = TEXT("/Game/Blueprints/System/Active/Anpan.Anpan");

// 生成.
AAnpan *AAnpan::Spawn(UWorld *pWorld, const AnpanData &Data)
{
	AAnpan *pAnpan = Util::SpawnFromBlueprint<AAnpan>(pWorld, BlueprintPath, FVector(Data.X, Data.Y, 100.0f), FRotator(0.0f, 0.0f, 0.0f));
	pAnpan->Initialize(Data.Hp, Data.MaxHp);
	pAnpan->Uuid = Data.Uuid;

	return pAnpan;
}

// コンストラクタ
AAnpan::AAnpan(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, "MeshComponent");

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(MeshPath);
	pMeshComponent->SetStaticMesh(MeshFinder.Object);
	pMeshComponent->AddWorldRotation(FRotator(0.0f, 90.0f, 0.0f));
	pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	pMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);

	RootComponent = pMeshComponent;
}
