// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "CharacterBase.h"

// コンストラクタ
ACharacterBase::ACharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Hp(1)
	, MaxHp(1)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// ダメージを与える。
void ACharacterBase::ApplyDamage(int32 Value)
{
	if (IsDead()) { return; }
	Hp = FMath::Max<int32>(Hp - Value, 0);
	if (IsDead())
	{
		OnDead();
	}
}


// 初期化.
void ACharacterBase::Initialize(int32 InHp, int32 InMaxHp)
{
	Hp = InHp;
	MaxHp = InMaxHp;
}
