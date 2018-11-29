// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyInfoMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Util.h"
#include "Packet/PacketPartyDissolutionRequest.h"

const TCHAR *UPartyInfoMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/Party/PartyInfoMenu.PartyInfoMenu");

// ����.
UPartyInfoMenuWidget *UPartyInfoMenuWidget::Create(UObject *pOuter)
{
	UPartyInfoMenuWidget *pWidget = Util::LoadBlueprint<UPartyInfoMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// �R���X�g���N�^
UPartyInfoMenuWidget::UPartyInfoMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// ���U���N�G�X�g�𑗐M.
void UPartyInfoMenuWidget::SendDissolutionRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyDissolutionRequest Packet;
	pInst->SendPacket(&Packet);
}
