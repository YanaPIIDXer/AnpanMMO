// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "BuffIcon.h"

// �R���X�g���N�^
UBuffIcon::UBuffIcon(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Type(EBuffType::Invalid)
	, BuffTime(0.1f)
	, LastTime(0.1f)
{
}

// �Z�b�g�A�b�v
void UBuffIcon::Setup(EBuffType InType, float Time)
{
	Type = InType;
	BuffTime = Time;
	LastTime = Time;

	OnSetup();
}

// ���t���[���̏���.
void UBuffIcon::NativeTick(const FGeometry &InGeometry, float InDeltaTime)
{
	Super::NativeTick(InGeometry, InDeltaTime);

	LastTime -= InDeltaTime;

	// �~���c��ɂ��Ă����B
	// �����ł̓T�[�o����̃p�P�b�g���󂯎�������B
	if (LastTime < 0.1f)
	{
		LastTime = 0.1f;
	}
}

// �o�t���H
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
