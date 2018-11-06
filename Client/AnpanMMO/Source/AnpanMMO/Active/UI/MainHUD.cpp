// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MainHUD.h"
#include "Util.h"

const TCHAR *UMainHUD::AssetPath = TEXT("/Game/Blueprints/UI/Active/MainHUD.MainHUD");

// �\��.
UMainHUD *UMainHUD::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UMainHUD>(pOuter, AssetPath);
	check(pWidget != nullptr);
	return pWidget;
}

// �R���X�g���N�^
UMainHUD::UMainHUD(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}
