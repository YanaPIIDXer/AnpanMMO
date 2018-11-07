// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "Character/Anpan/Anpan.h"
#include "MMOGameInstance.h"
#include "Packet/PacketAttack.h"

const TCHAR *AGameCharacter::AnimInstanceClassPath = TEXT("/Game/Meshes/Player/Animations/GameCharacterAnimBP.GameCharacterAnimBP_C");

// �R���X�g���N�^
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");

	UClass *pAnimClass = LoadObject<UClass>(this, AnimInstanceClassPath, AnimInstanceClassPath);
	check(pAnimClass != nullptr);
	GetMeshComponent()->SetAnimInstanceClass(pAnimClass);
}

// �J�n���̏���.
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	Status = pInst->GetStatusCache();
	Initialize(Status.GetMaxHp(), Status.GetMaxHp());
}

// �U��.
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

// �o���l����M�����B
void AGameCharacter::OnRecvExp(int32 Exp)
{
	Status.SetExp(Exp);
}

// ���x���A�b�v�����B
void AGameCharacter::OnLevelUp(int32 MaxHp, int32 Atk, int32 Def)
{
	Status.Set(MaxHp, Atk, Def);
	UpdateMaxHp(MaxHp);
}
