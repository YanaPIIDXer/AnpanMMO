// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "CharacterBase.h"

// �R���X�g���N�^
ACharacterBase::ACharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Hp(1)
	, MaxHp(1)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// �_���[�W��^����B
void ACharacterBase::ApplyDamage(int32 Value)
{
	if (IsDead()) { return; }
	Hp = FMath::Max<int32>(Hp - Value, 0);
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
