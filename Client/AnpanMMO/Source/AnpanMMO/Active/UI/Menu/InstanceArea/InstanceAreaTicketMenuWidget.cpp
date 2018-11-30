// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "InstanceAreaTicketMenuWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketInstanceAreaTicketProcess.h"

const TCHAR *UInstanceAreaTicketMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/InstanceAreaTicket/InstanceAreaTicketMenu.InstanceAreaTicketMenu");

// 表示.
void UInstanceAreaTicketMenuWidget::ShowWidget(UObject *pOuter, uint32 TicketId)
{
	auto *pWidget = Util::LoadBlueprint<UInstanceAreaTicketMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->TicketId = TicketId;
	pWidget->Show();
}

// コンストラクタ
UInstanceAreaTicketMenuWidget::UInstanceAreaTicketMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, TicketId(0)
{
}


// 参加を送信.
void UInstanceAreaTicketMenuWidget::SendEnter()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketInstanceAreaTicketProcess Packet(TicketId, PacketInstanceAreaTicketProcess::Enter);
	pInst->SendPacket(&Packet);
}

// 破棄を送信.
void UInstanceAreaTicketMenuWidget::SendDiscard()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketInstanceAreaTicketProcess Packet(TicketId, PacketInstanceAreaTicketProcess::Discard);
	pInst->SendPacket(&Packet);
}
