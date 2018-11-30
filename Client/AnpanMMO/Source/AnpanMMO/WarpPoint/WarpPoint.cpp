// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpPoint.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Active/UI/WarpAreaList.h"
#include "Master/MasterData.h"
#include "MMOGameInstance.h"
#include "Character/Player/GameController.h"
#include "Packet/PacketAreaMoveRequest.h"

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

// �R���X�g���N�^
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

// ���t���[���̏���.
void AWarpPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bInitialized)
	{
		// ���̂����������u�ԂɃI�[�o�[���b�v�C�x���g�������Ă���̂łP�t���[���x��������B
		pCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		pCollisionComponent->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel2);
		pCollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		pCollisionComponent->SetGenerateOverlapEvents(true);
		pCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AWarpPoint::OnOverlap);
		bInitialized = true;
	}
}

// �Փ˃C�x���g
void AWarpPoint::OnOverlap(UPrimitiveComponent *pOverlappedComponent, AActor *pOtherActor, UPrimitiveComponent *pOtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (pOtherActor != UGameplayStatics::GetPlayerPawn(this, 0)) { return; }
	auto AllList = MasterData::GetInstance().GetWarpDataMaster().GetAll();
	TArray<WarpDataItem> ItemList;
	for (const auto &Item : AllList)
	{
		if (Item.WarpDataId == Id)
		{
			ItemList.Add(Item);
		}
	}

	if (ItemList.Num() > 1)
	{
		// �ړ��悪��������Ȃ烁�j���[��\��.
		UWarpAreaList::Create(this, Id);
	}
	else
	{
		// �ړ��悪������Ȃ�ⓚ���p�ł����Ɉړ��B
		AGameController *pController = Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));
		check(pController != nullptr);
		pController->SetEnableMove(false);

		UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
		check(pInst != nullptr);

		pInst->SetAreaIdCache(ItemList[0].AreaId);
		PacketAreaMoveRequest Packet(ItemList[0].ID);
		pInst->SendPacket(&Packet);
	}
}
