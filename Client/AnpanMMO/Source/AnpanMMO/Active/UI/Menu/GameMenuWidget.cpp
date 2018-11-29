// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameMenuWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"

const TCHAR *UGameMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/GameMenu.GameMenu");

// �\��.
UGameMenuWidget *UGameMenuWidget::ShowWidget(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UGameMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->Show(1);
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

	auto *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->OnCloseGameMenu();
}
