// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpPoint.h"
#include "UObject/ConstructorHelpers.h"
#include "Master/MasterData.h"
#include "Kismet/GameplayStatics.h"

const float AWarpPoint::CollisionRadius = 300.0f;
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
	UE_LOG(LogTemp, Log, TEXT("WarpDatas Count:%d"), WarpDatas.Num());
	for (const auto *pData : WarpDatas)
	{
		UE_LOG(LogTemp, Log, TEXT("AreaId:%d X:%f Y:%f"), pData->AreaId, pData->X, pData->Y);
	}
}


// 初期化.
void AWarpPoint::Initialize(uint32 Id)
{
	WarpDatas = MasterData::GetInstance().GetWarpDataMaster().CollectItems(Id);
}
