// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "Character/Anpan/Anpan.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketAttack.h"

const TCHAR *AGameCharacter::AnimInstanceClassPath = TEXT("/Game/Meshes/Player/Animations/GameCharacterAnimBP.GameCharacterAnimBP_C");

// �R���X�g���N�^
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
}

// �J�n���̏���.
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	UClass *pAnimClass = LoadObject<UClass>(this, AnimInstanceClassPath, AnimInstanceClassPath);
	check(pAnimClass != nullptr);
	GetMeshComponent()->SetAnimInstanceClass(pAnimClass);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	Status = pInst->GetStatusCache();
	Initialize(Status.GetMaxHp(), Status.GetMaxHp());

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->AddPlayerCharacter(Status.GetUuid(), this);
}

// �U��.
void AGameCharacter::Attack()
{
	FHitResult Result;

	FVector StartVec = GetActorLocation();
	FVector EndVec = StartVec + (GetActorForwardVector() * 500.0f);
	if (!GetWorld()->LineTraceSingleByChannel(Result, StartVec, EndVec, ECollisionChannel::ECC_GameTraceChannel1)) { return; }
	AAnpan *pAnpan = Cast<AAnpan>(Result.GetActor());
	if (pAnpan == nullptr) { return; }

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	PacketAttack Packet(pAnpan->GetUuid());
	pInst->SendPacket(&Packet);
}

// �o���l����M�����B
void AGameCharacter::OnRecvExp(int32 Exp)
{
	Status.SetExp(Exp);
}

// ���x���A�b�v����M�����B
void AGameCharacter::OnRecvLevelUp(int32 MaxHp, int32 Atk, int32 Def)
{
	Status.Set(MaxHp, Atk, Def);
	UpdateMaxHp(MaxHp);
	OnLevelUp();
}
