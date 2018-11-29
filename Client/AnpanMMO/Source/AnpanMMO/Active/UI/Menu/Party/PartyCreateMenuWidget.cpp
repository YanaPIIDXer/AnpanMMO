// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyCreateMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketPartyCreateRequest.h"
#include "Util.h"

const TCHAR *UPartyCreateMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/Party/PartyCreateMenu.PartyCreateMenu");

// 生成.
UPartyCreateMenuWidget *UPartyCreateMenuWidget::Create(UObject *pOuter)
{
	UPartyCreateMenuWidget *pWidget = Util::LoadBlueprint<UPartyCreateMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// コンストラクタ
UPartyCreateMenuWidget::UPartyCreateMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// パーティ作成リクエスト送信.
void UPartyCreateMenuWidget::SendPartyCreateRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyCreateRequest Packet;
	pInst->SendPacket(&Packet);
}
