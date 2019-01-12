// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "PartyMemberInfoMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketPartyKickRequest.h"

// コンストラクタ
UPartyMemberInfoMenuWidget::UPartyMemberInfoMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 初期化.
void UPartyMemberInfoMenuWidget::Init(bool bInIsLeader, const FPartyMemberData &InData)
{
	bIsLeader = bInIsLeader;
	Data = InData;
}


// キックする
void UPartyMemberInfoMenuWidget::Kick()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyKickRequest Packet(Data.Uuid);
	pInst->SendPacket(&Packet);
}
