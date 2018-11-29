// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameMenuWidget.h"
#include "Util.h"

const TCHAR *UGameMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/GameMenu.GameMenu");
const int UGameMenuWidget::ZOrder = 1;

// �\��.
UGameMenuWidget *UGameMenuWidget::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UGameMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport(ZOrder);
	return pWidget;
}

// �R���X�g���N�^
UGameMenuWidget::UGameMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// �p�[�e�B���j���[�\��.
void UGameMenuWidget::ShowPartyMenu()
{
	UE_LOG(LogTemp, Log, TEXT("Show Party Menu"));
}

// ���j���[�����
void UGameMenuWidget::CloseMenu()
{
	RemoveFromParent();
}
