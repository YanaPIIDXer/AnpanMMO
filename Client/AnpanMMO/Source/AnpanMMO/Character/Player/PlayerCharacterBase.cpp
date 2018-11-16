// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerCharacterBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/SkeletalMesh.h"
#include "Components/SphereComponent.h"

const TCHAR *APlayerCharacterBase::MeshPath = TEXT("/Game/Meshes/Player/Character/Mesh/SK_Mannequin.SK_Mannequin");
const TCHAR *APlayerCharacterBase::AnimInstanceClassPath = TEXT("/Game/Meshes/Player/Animations/GameCharacterAnimBP.GameCharacterAnimBP_C");

// コンストラクタ
APlayerCharacterBase::APlayerCharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	USphereComponent *pDummyComponent = CreateDefaultSubobject<USphereComponent>("Dummy");
	pDummyComponent->bHiddenInGame = true;
	pDummyComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	RootComponent = pDummyComponent;

	pMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshFinder(MeshPath);
	pMeshComponent->SetSkeletalMesh(MeshFinder.Object);

	pMeshComponent->SetupAttachment(pDummyComponent);
	pMeshComponent->SetRelativeLocation(FVector(0, 0, -110.0f));
	pMeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	pMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	pMeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Overlap);
	pMeshComponent->SetGenerateOverlapEvents(true);
	SetActorEnableCollision(true);
}

// 開始時の処理.
void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	UClass *pAnimClass = LoadObject<UClass>(this, AnimInstanceClassPath, AnimInstanceClassPath);
	check(pAnimClass != nullptr);
	pMeshComponent->SetAnimInstanceClass(pAnimClass);
}

// リスポン
void APlayerCharacterBase::Respawn(float X, float Y)
{
	OnRespawn();
	
	SetActorLocation(FVector(X, Y, GetActorLocation().Z));
}
