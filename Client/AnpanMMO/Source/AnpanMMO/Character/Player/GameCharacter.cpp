// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "Character/Anpan/Anpan.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Active/UI/MainHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketAttack.h"

// コンストラクタ
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");

}

// 開始時の処理.
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	Status = pInst->GetStatusCache();
	Initialize(Status.GetMaxHp(), Status.GetMaxHp());

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->AddPlayerCharacter(Status.GetUuid(), this);

	Move.Initialize(this, pInst);
}

// 毎フレームの処理.
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move.Poll(DeltaTime);
}

// 攻撃.
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

// 経験値を受信した。
void AGameCharacter::OnRecvExp(int32 Exp)
{
	Status.SetExp(Exp);
}

// レベルアップを受信した。
void AGameCharacter::OnRecvLevelUp(int32 MaxHp, int32 Atk, int32 Def)
{
	Status.Set(MaxHp, Atk, Def);
	UpdateMaxHp(MaxHp);
	OnLevelUp();
}

// 移動ベクトルの取得.
FVector AGameCharacter::GetMoveVector() const
{
	return pMovementComponent->GetLastInputVector();
}


// リスポンした。
void AGameCharacter::OnRespawn()
{
	SetHP(Status.GetMaxHp());

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->GetMainHUD()->OnRespawn();
}
