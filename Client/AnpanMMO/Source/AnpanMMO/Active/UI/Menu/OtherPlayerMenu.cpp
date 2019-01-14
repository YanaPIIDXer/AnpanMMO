// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerMenu.h"
#include "Character/Player/Other/OtherPlayerCharacter.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Packet/PacketPartyInviteRequest.h"

// コンストラクタ
UOtherPlayerMenu::UOtherPlayerMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, CharacterName("")
	, CharacterUuid(0)
{
}

// セットアップ
void UOtherPlayerMenu::Setup(AOtherPlayerCharacter *pCharacter)
{
	CharacterName = pCharacter->GetCharacterName();
	CharacterUuid = pCharacter->GetUuid();
}

// パーティに勧誘できるか？
bool UOtherPlayerMenu::IsAblePartyInvite() const
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	const PartyInformation &PartyInfo = pGameMode->GetPartyInfo();

	// @TODO;メンバが最大かどうか等、他にチェックする事がある。
	return PartyInfo.IsJoined();
}

// パーティ勧誘を送信.
void UOtherPlayerMenu::SendPartyInvite()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyInviteRequest Packet(CharacterUuid);
	pInst->SendPacket(&Packet);
}
