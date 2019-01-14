// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerMenu.h"
#include "Character/Player/Other/OtherPlayerCharacter.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Packet/PacketPartyInviteRequest.h"

// �R���X�g���N�^
UOtherPlayerMenu::UOtherPlayerMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, CharacterName("")
	, CharacterUuid(0)
{
}

// �Z�b�g�A�b�v
void UOtherPlayerMenu::Setup(AOtherPlayerCharacter *pCharacter)
{
	CharacterName = pCharacter->GetCharacterName();
	CharacterUuid = pCharacter->GetUuid();
}

// �p�[�e�B�Ɋ��U�ł��邩�H
bool UOtherPlayerMenu::IsAblePartyInvite() const
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	const PartyInformation &PartyInfo = pGameMode->GetPartyInfo();

	// @TODO;�����o���ő傩�ǂ������A���Ƀ`�F�b�N���鎖������B
	return PartyInfo.IsJoined();
}

// �p�[�e�B���U�𑗐M.
void UOtherPlayerMenu::SendPartyInvite()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyInviteRequest Packet(CharacterUuid);
	pInst->SendPacket(&Packet);
}
