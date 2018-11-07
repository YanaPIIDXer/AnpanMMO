// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "Character/Anpan/Anpan.h"
#include "MMOGameInstance.h"
#include "Packet/PacketAttack.h"

const TCHAR *AGameCharacter::AnimInstanceClassPath = TEXT("/Game/Meshes/Player/Animations/GameCharacterAnimBP.GameCharacterAnimBP_C");

// コンストラクタ
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

// 経験値を受信した。
void AGameCharacter::OnRecvExp(int32 Exp)
{
	Status.SetExp(Exp);
}

// レベルアップした。
void AGameCharacter::OnLevelUp(int32 MaxHp, int32 Atk, int32 Def)
{
	Status.Set(MaxHp, Atk, Def);
	UpdateMaxHp(MaxHp);
}
