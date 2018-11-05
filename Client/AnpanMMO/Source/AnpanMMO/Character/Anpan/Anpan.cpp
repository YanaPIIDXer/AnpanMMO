// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Anpan.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Packet/AnpanData.h"

const TCHAR *AAnpan::MeshPath = TEXT("/Game/Meshes/Anpan/Mesh/Anpan.Anpan");

// 生成.
AAnpan *AAnpan::Spawn(UWorld *pWorld, const AnpanData &Data)
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AAnpan *pAnpan = pWorld->SpawnActor<AAnpan>(FVector(Data.X, Data.Y, 100.0f), FRotator(0.0f, 0.0f, 0.0f), Param);
	check(pAnpan != nullptr);

	pAnpan->Hp = Data.Hp;
	pAnpan->MaxHp = Data.MaxHp;

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

	RootComponent = pMeshComponent;
}
