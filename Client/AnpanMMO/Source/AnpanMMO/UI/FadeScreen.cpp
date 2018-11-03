// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "FadeScreen.h"

const float UFadeScreen::AlphaSpeedBySec = 0.5f;

// コンストラクタ
UFadeScreen::UFadeScreen(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, AlphaValue(0.0f)
	, FadeMode(EFadeMode::None)
{
}

// 毎フレームの処理.
void UFadeScreen::NativeTick(const FGeometry &Geometry, float DeltaTime)
{
	Super::NativeTick(Geometry, DeltaTime);
	if (FadeMode == EFadeMode::None) { return; }

	float Speed = AlphaSpeedBySec * DeltaTime;
	switch (FadeMode)
	{
		case EFadeMode::FadeIn:

			AlphaValue -= Speed;
			break;

		case EFadeMode::FadeOut:

			AlphaValue += Speed;
			break;
	}

	if (FadeMode == EFadeMode::FadeIn && AlphaValue <= 0.0f)
	{
		AlphaValue = 0.0f;
		OnFadeFinished.Broadcast();
		FadeMode = EFadeMode::None;
	}
	else if (FadeMode == EFadeMode::FadeOut && AlphaValue >= 1.0f)
	{
		AlphaValue = 1.0f;
		OnFadeFinished.Broadcast();
		FadeMode = EFadeMode::None;
	}
}

// フェード開始.
void UFadeScreen::Start(EFadeMode Mode)
{
	check(Mode != EFadeMode::None);

	FadeMode = Mode;
	switch (FadeMode)
	{
		case EFadeMode::FadeIn:

			AlphaValue = 1.0f;
			break;

		case EFadeMode::FadeOut:

			AlphaValue = 0.0f;
			break;
	}
}
