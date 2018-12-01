// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "InstanceAreaTicketMenuWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketInstanceAreaTicketProcess.h"

const TCHAR *UInstanceAreaTicketMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/InstanceAreaTicket/InstanceAreaTicketMenu.InstanceAreaTicketMenu");

// �\��.
void UInstanceAreaTicketMenuWidget::ShowWidget(UObject *pOuter, uint32 TicketId)
{
	auto *pWidget = Util::LoadBlueprint<UInstanceAreaTicketMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->TicketId = TicketId;
	pWidget->Show();
}

// �R���X�g���N�^
UInstanceAreaTicketMenuWidget::UInstanceAreaTicketMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, TicketId(0)
{
}


// �Q���𑗐M.
void UInstanceAreaTicketMenuWidget::SendEnter()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketInstanceAreaTicketProcess Packet(TicketId, PacketInstanceAreaTicketProcess::Enter);
	pInst->SendPacket(&Packet);
}

// �j���𑗐M.
void UInstanceAreaTicketMenuWidget::SendDiscard()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketInstanceAreaTicketProcess Packet(TicketId, PacketInstanceAreaTicketProcess::Discard);
	pInst->SendPacket(&Packet);
}
