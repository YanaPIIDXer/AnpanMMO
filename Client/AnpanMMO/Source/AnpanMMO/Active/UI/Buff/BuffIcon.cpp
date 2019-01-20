// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "BuffIcon.h"

// コンストラクタ
UBuffIcon::UBuffIcon(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Type(EBuffType::Invalid)
	, BuffTime(0.1f)
	, LastTime(0.1f)
{
}

// セットアップ
void UBuffIcon::Setup(EBuffType InType, float Time)
{
	Type = InType;
	BuffTime = Time;
	LastTime = Time;

	OnSetup();
}

// 毎フレームの処理.
void UBuffIcon::NativeTick(const FGeometry &InGeometry, float InDeltaTime)
{
	Super::NativeTick(InGeometry, InDeltaTime);

	LastTime -= InDeltaTime;

	// ミリ残りにしておく。
	// ※消滅はサーバからのパケットを受け取った時。
	if (LastTime < 0.1f)
	{
		LastTime = 0.1f;
	}
}

// バフか？
bool UBuffIcon::IsBuff() const
{
	switch (Type)
	{
		case EBuffType::SpeedUp:
		case EBuffType::AutoHeal:

			return true;
	}

	return false;
}
