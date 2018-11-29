// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MainHUD.h"
#include "Util.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Packet/NoticeData.h"

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
	UE_LOG(LogTemp, Log, TEXT("OnRecvNotice UUID:%d Type:%d CustomerId:%d"), Uuid, Data.Type, Data.CustomerId);
}


// 攻撃ボタンが押された。
void UMainHUD::OnPressedAttackButton()
{
	pCharacter->Attack();
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

// ゲームメニュー表示.
void UMainHUD::ShowGameMenu()
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->ShowGameMenu();
}
