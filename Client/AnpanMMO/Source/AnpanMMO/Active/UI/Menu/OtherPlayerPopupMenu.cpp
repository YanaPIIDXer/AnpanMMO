// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerPopupMenu.h"
#include "Character/Player/Other/OtherPlayerCharacter.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Packet/PacketPartyInviteRequest.h"

const TCHAR *UOtherPlayerPopupMenu::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/OtherPlayerPopupMenu.OtherPlayerPopupMenu");

// 表示.
UOtherPlayerPopupMenu *UOtherPlayerPopupMenu::Show(UObject *pOuter, AOtherPlayerCharacter *pCharacter)
{
	UOtherPlayerPopupMenu *pWidget = Util::LoadBlueprint<UOtherPlayerPopupMenu>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->CharacterName = pCharacter->GetCharacterName();
	pWidget->CharacterUuid = pCharacter->GetUuid();

	auto *pController = UGameplayStatics::GetPlayerController(pOuter, 0);
	check(pController != nullptr);

	pWidget->AddToViewport();
	FVector2D DisplayPosition = FVector2D::ZeroVector;
	pController->ProjectWorldLocationToScreen(pCharacter->GetActorLocation(), DisplayPosition);
	pWidget->SetPositionInViewport(DisplayPosition);

	return pWidget;
}


// コンストラクタ
UOtherPlayerPopupMenu::UOtherPlayerPopupMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, CharacterName("")
	, CharacterUuid(0)
{
}


// パーティに勧誘できるか？
bool UOtherPlayerPopupMenu::IsAblePartyInvite() const
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	const PartyInformation &PartyInfo = pGameMode->GetPartyInfo();

	// @TODO;メンバが最大かどうか等、他にチェックする事がある。
	return PartyInfo.IsJoined();
}

// パーティ勧誘を送信.
void UOtherPlayerPopupMenu::SendPartyInvite()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyInviteRequest Packet(CharacterUuid);
	pInst->SendPacket(&Packet);
}

// メニューを消去.
void UOtherPlayerPopupMenu::EraseMenu()
{
}
