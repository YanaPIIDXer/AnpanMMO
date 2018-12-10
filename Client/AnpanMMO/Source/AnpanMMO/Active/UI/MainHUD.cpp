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

// 表示.
UMainHUD *UMainHUD::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UMainHUD>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport();
	return pWidget;
}

// コンストラクタ
UMainHUD::UMainHUD(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
	, NotReadNoticeCount(0)
{
}

// 開始時の処理.
void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();

	pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// 通知を受信した。
void UMainHUD::OnRecvNotice(int32 Uuid, const NoticeData &Data)
{
	NotReadNoticeCount++;
}


// 攻撃ボタンが押された。
void UMainHUD::OnPressedAttackButton()
{
	
}

// レベルロード開始.
void UMainHUD::StartLevelLoad()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	
	uint32 AreaId = pInst->GetAreaIdCache();
	pGameMode->StartLevelLoad(AreaId);
}

// ゲームメニューを表示.
void UMainHUD::ShowGameMenu()
{
	UGameMenuWidget::ShowWidget(this);
}

// 通知メニューを表示.
void UMainHUD::ShowNoticeMenu()
{
	NotReadNoticeCount = 0;
	UNoticeMenuWidget::ShowWidget(this);
}
