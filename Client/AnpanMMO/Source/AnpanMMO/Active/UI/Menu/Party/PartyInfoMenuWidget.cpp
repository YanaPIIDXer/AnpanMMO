// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyInfoMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Util.h"
#include "Packet/PacketPartyDissolutionRequest.h"

const TCHAR *UPartyInfoMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/Party/PartyInfoMenu.PartyInfoMenu");

// 生成.
UPartyInfoMenuWidget *UPartyInfoMenuWidget::Create(UObject *pOuter)
{
	UPartyInfoMenuWidget *pWidget = Util::LoadBlueprint<UPartyInfoMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// コンストラクタ
UPartyInfoMenuWidget::UPartyInfoMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// 解散リクエストを送信.
void UPartyInfoMenuWidget::SendDissolutionRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyDissolutionRequest Packet;
	pInst->SendPacket(&Packet);
}
