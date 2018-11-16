// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MainHUD.h"
#include "Util.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketGameReady.h"

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


// 攻撃ボタンが押された。
void UMainHUD::OnPressedAttackButton()
{
	pCharacter->Attack();
}

// 準備完了パケットを送信.
void UMainHUD::SendReadyPacket()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketGameReady Packet;
	pInst->SendPacket(&Packet);
}
