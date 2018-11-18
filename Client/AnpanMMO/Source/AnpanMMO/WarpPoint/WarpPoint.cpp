// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpPoint.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Active/UI/WarpAreaList.h"

const float AWarpPoint::CollisionRadius = 300.0f;
const TCHAR *AWarpPoint::ParticlePath = TEXT("/Game/Effects/Effects/FX_Mobile/Fire/combat/P_AuraCircle_Fire_02.P_AuraCircle_Fire_02");

// Spawn
AWarpPoint *AWarpPoint::Spawn(UWorld *pWorld, float X, float Y, float Z, uint32 InId)
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AWarpPoint *pWarpPoint = pWorld->SpawnActor<AWarpPoint>(FVector(X, Y, Z), FRotator::ZeroRotator, Param);
	check(pWarpPoint != nullptr);
	pWarpPoint->Id = InId;

	return pWarpPoint;
}

// コンストラクタ
AWarpPoint::AWarpPoint(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, bInitialized(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pCollisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, "CollisionComponent");
	pCollisionComponent->SetSphereRadius(CollisionRadius);
	
	pParticleComponent = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, "ParticleSystem");
	
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleFinder(ParticlePath);
	pParticleComponent->SetTemplate(ParticleFinder.Object);

	RootComponent = pCollisionComponent;
	pParticleComponent->SetupAttachment(RootComponent);
	SetActorEnableCollision(true);
}

// 毎フレームの処理.
void AWarpPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bInitialized)
	{
		// 何故か生成した瞬間にオーバーラップイベントが走っているので１フレーム遅延させる。
		pCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		pCollisionComponent->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel2);
		pCollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		pCollisionComponent->SetGenerateOverlapEvents(true);
		pCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AWarpPoint::OnOverlap);
		bInitialized = true;
	}
}

// 衝突イベント
void AWarpPoint::OnOverlap(UPrimitiveComponent *pOverlappedComponent, AActor *pOtherActor, UPrimitiveComponent *pOtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (pOtherActor != UGameplayStatics::GetPlayerPawn(this, 0)) { return; }

	UWarpAreaList::Create(this, Id);
}
