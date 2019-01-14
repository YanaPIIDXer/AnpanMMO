// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "PlayerHPGauge.h"

const float UPlayerHPGauge::MutateTime = 1.0f;

// コンストラクタ
UPlayerHPGauge::UPlayerHPGauge(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, ProgressRate(1.0f)
	, CurrentHp(0)
	, PrevHp(0)
	, MaxHp(0)
	, CurrentTime(0.0f)
{
}

// 毎フレームの処理.
void UPlayerHPGauge::NativeTick(const FGeometry &InGeometry, float InDeltaTime)
{
	Super::NativeTick(InGeometry, InDeltaTime);
	if (CurrentTime > 0.0f)
	{
		CurrentTime = FMath::Max<float>(CurrentTime - InDeltaTime, 0.0f);
		float CurrentHpRate = (float)CurrentHp / MaxHp;
		float PrevHpRate = (float)PrevHp / MaxHp;
		ProgressRate = FMath::Lerp<float>(PrevHpRate, CurrentHpRate, 1.0f - (CurrentTime / MutateTime));
	}
}

// 初期化.
void UPlayerHPGauge::Init(int32 InCurrentHp, int32 InMaxHp)
{
	CurrentHp = InCurrentHp;
	PrevHp = InCurrentHp;
	MaxHp = InMaxHp;
}

// リスポンした
void UPlayerHPGauge::Respawn()
{
	CurrentHp = MaxHp;
	PrevHp = 0;
	CurrentTime = MutateTime;
}

// ダメージを受けた。
void UPlayerHPGauge::Damaged(int32 Value)
{
	PrevHp = CurrentHp;
	CurrentHp = FMath::Max<int32>(CurrentHp - Value, 0);
	CurrentTime = MutateTime;
}

// 回復した。
void UPlayerHPGauge::Healed(int32 Value)
{
	PrevHp = CurrentHp;
	CurrentHp = FMath::Min<int32>(CurrentHp + Value, MaxHp);
	CurrentTime = MutateTime;
}

// レベルアップ
void UPlayerHPGauge::LevelUp(int32 InMaxHp)
{
	MaxHp = InMaxHp;
	CurrentTime = MutateTime;
}
