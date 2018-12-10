// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MainHUD.h"
#include "Util.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Packet/NoticeData.h"
#include "Menu/GameMenuWidget.h"
#include "Menu/Notice/NoticeMenuWidget.h"

const TCHAR *UMainHUD::AssetPath = TEXT("/Game/Blueprints/UI/Active/MainHUD.MainHUD");

// �\��.
UMainHUD *UMainHUD::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UMainHUD>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport();
	return pWidget;
}

// �R���X�g���N�^
UMainHUD::UMainHUD(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, NotReadNoticeCount(0)
{
}

// �J�n���̏���.
void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();

	pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// �ʒm����M�����B
void UMainHUD::OnRecvNotice(int32 Uuid, const NoticeData &Data)
{
	NotReadNoticeCount++;
}


// �U���{�^���������ꂽ�B
void UMainHUD::OnPressedAttackButton()
{
	
}

// ���x�����[�h�J�n.
void UMainHUD::StartLevelLoad()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	
	uint32 AreaId = pInst->GetAreaIdCache();
	pGameMode->StartLevelLoad(AreaId);
}

// �Q�[�����j���[��\��.
void UMainHUD::ShowGameMenu()
{
	UGameMenuWidget::ShowWidget(this);
}

// �ʒm���j���[��\��.
void UMainHUD::ShowNoticeMenu()
{
	NotReadNoticeCount = 0;
	UNoticeMenuWidget::ShowWidget(this);
}
