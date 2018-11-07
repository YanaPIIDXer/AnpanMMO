// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/SkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Character/Anpan/Anpan.h"
#include "MMOGameInstance.h"
#include "Packet/PacketAttack.h"

const TCHAR *AGameCharacter::MeshPath = TEXT("/Game/Meshes/Player/Character/Mesh/SK_Mannequin.SK_Mannequin");
const TCHAR *AGameCharacter::AnimInstanceClassPath = TEXT("/Game/Meshes/Player/Animations/GameCharacterAnimBP.GameCharacterAnimBP_C");

// コンストラクタ
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");

	pMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshFinder(MeshPath);
	pMeshComponent->SetSkeletalMesh(MeshFinder.Object);
	pMeshComponent->SetWorldLocation(FVector(0, 0, -110.0f));
	pMeshComponent->SetWorldRotation(FRotator(0.0f, -90.0f, 0.0f));
	UClass *pAnimClass = LoadObject<UClass>(this, AnimInstanceClassPath, AnimInstanceClassPath);
	check(pAnimClass != nullptr);
	pMeshComponent->SetAnimInstanceClass(pAnimClass);

	RootComponent = pMeshComponent;
}

// 開始時の処理.
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	Status = pInst->GetStatusCache();
	Initialize(Status.GetMaxHp(), Status.GetMaxHp());
}

// 攻撃.
void AGameCharacter::Attack()
{
	FHitResult Result;

	if (!GetWorld()->LineTraceSingleByChannel(Result, GetActorLocation(), GetActorLocation() + (GetActorForwardVector() * 500.0f), ECollisionChannel::ECC_GameTraceChannel1)) { return; }
	AAnpan *pAnpan = Cast<AAnpan>(Result.GetActor());
	if (pAnpan == nullptr) { return; }

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	PacketAttack Packet(pAnpan->GetUuid());
	pInst->SendPacket(&Packet);
}
