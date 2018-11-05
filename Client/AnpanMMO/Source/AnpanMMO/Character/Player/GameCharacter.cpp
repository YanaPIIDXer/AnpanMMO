// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "Character/Anpan/Anpan.h"
#include "MMOGameInstance.h"
#include "Packet/PacketAttack.h"

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
	
}

// ���t���[���̏���.
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
