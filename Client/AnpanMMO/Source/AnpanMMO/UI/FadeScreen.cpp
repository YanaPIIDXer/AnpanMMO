// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "FadeScreen.h"

const float UFadeScreen::AlphaSpeedBySec = 0.3f;

// �R���X�g���N�^
UFadeScreen::UFadeScreen(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, AlphaValue(0.0f)
	, FadeMode(EFadeMode::None)
{
}

// ���t���[���̏���.
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
	AlphaValue = FMath::Clamp<float>(AlphaValue, 0.0f, 1.0f);
}

// �t�F�[�h�J�n.
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
