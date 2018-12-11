// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "TargetCircle/TargetCircle.h"

// コンストラクタ
ACharacterBase::ACharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Hp(1)
	, MaxHp(1)
	, pTargetCircle(nullptr)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto *pCollisionComponent = GetCapsuleComponent();
	pCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	pCollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);

	auto *pMeshComponent = GetMesh();
	pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	pMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	pMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	pMeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);
	pMeshComponent->SetGenerateOverlapEvents(true);
	SetActorEnableCollision(true);
}

// ダメージを与える。
void ACharacterBase::ApplyDamage(int32 Value)
{
	if (IsDead()) { return; }
	int32 BeforeHp = Hp;
	Hp = FMath::Max<int32>(Hp - Value, 0);

	OnDamaged(BeforeHp, Hp, Value);

	if (IsDead())
	{
		OnDead();
	}
}

// 回復.
void ACharacterBase::Heal(int32 Value)
{
	int32 BeforeHp = Hp;
	Hp = FMath::Min<int32>(Hp + Value, MaxHp);

	OnHeal(BeforeHp, Hp, Value);
}

// ターゲットサークルを生成.
void ACharacterBase::SpawnTargetCircle()
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pTargetCircle = GetWorld()->SpawnActor<ATargetCircle>(Param);
	check(pTargetCircle != nullptr);

	pTargetCircle->SetCharacter(this);
}

// ターゲットサークルを撤去.
void ACharacterBase::DestroyTargetCircle()
{
	if (pTargetCircle == nullptr) { return; }
	pTargetCircle->Destroy();
	pTargetCircle = nullptr;
}


// 初期化.
void ACharacterBase::Initialize(int32 InHp, int32 InMaxHp)
{
	Hp = InHp;
	MaxHp = InMaxHp;
}
