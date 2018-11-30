// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyMemberInfoMenuWidget.h"

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
	UE_LOG(LogTemp, Log, TEXT("%s Kick"), *Data.Name);
}
