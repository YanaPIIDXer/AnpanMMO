// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "CharacterBase.h"
#include "Components/CapsuleComponent.h"

// �R���X�g���N�^
ACharacterBase::ACharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Hp(1)
	, MaxHp(1)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto *pCollisionComponent = GetCapsuleComponent();
	pCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	pCollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
}

// �_���[�W��^����B
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


// ������.
void ACharacterBase::Initialize(int32 InHp, int32 InMaxHp)
{
	Hp = InHp;
	MaxHp = InMaxHp;
}
