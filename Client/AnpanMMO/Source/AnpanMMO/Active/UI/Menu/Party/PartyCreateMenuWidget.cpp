// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyCreateMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketPartyCreateRequest.h"
#include "Util.h"

const TCHAR *UPartyCreateMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/Party/PartyCreateMenu.PartyCreateMenu");

// ����.
UPartyCreateMenuWidget *UPartyCreateMenuWidget::Create(UObject *pOuter)
{
	UPartyCreateMenuWidget *pWidget = Util::LoadBlueprint<UPartyCreateMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// �R���X�g���N�^
UPartyCreateMenuWidget::UPartyCreateMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// �p�[�e�B�쐬���N�G�X�g���M.
void UPartyCreateMenuWidget::SendPartyCreateRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyCreateRequest Packet;
	pInst->SendPacket(&Packet);
}
