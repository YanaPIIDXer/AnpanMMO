// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyMemberInfoMenuWidget.h"

// �R���X�g���N�^
UPartyMemberInfoMenuWidget::UPartyMemberInfoMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ������.
void UPartyMemberInfoMenuWidget::Init(bool bInIsLeader, const FPartyMemberData &InData)
{
	bIsLeader = bInIsLeader;
	Data = InData;
}


// �L�b�N����
void UPartyMemberInfoMenuWidget::Kick()
{
	UE_LOG(LogTemp, Log, TEXT("%s Kick"), *Data.Name);
}
