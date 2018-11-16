// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpPoint.h"
#include "UObject/ConstructorHelpers.h"
#include "Master/MasterData.h"

const TCHAR *AWarpPoint::ParticlePath = TEXT("/Game/Effects/Effects/FX_Mobile/Fire/combat/P_AuraCircle_Fire_02.P_AuraCircle_Fire_02");

// Spawn
AWarpPoint *AWarpPoint::Spawn(UWorld *pWorld, float X, float Y, uint32 Id)
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AWarpPoint *pWarpPoint = pWorld->SpawnActor<AWarpPoint>(FVector(X, Y, 0.0f), FRotator::ZeroRotator, Param);
	check(pWarpPoint != nullptr);
	pWarpPoint->Initialize(Id);

	return pWarpPoint;
}

// コンストラクタ
AWarpPoint::AWarpPoint(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pParticleComponent = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, "ParticleSystem");
	pParticleComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleFinder(ParticlePath);
	pParticleComponent->SetTemplate(ParticleFinder.Object);
}


// 初期化.
void AWarpPoint::Initialize(uint32 Id)
{
	WarpDatas = MasterData::GetInstance().GetWarpDataMaster().CollectItems(Id);
}
