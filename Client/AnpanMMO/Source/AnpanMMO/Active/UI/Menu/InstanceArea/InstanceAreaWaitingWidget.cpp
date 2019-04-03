// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "InstanceAreaWaitingWidget.h"

// コンストラクタ
UInstanceAreaWaitingWidget::UInstanceAreaWaitingWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// パケットを受信した。
void UInstanceAreaWaitingWidget::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case PacketID::AreaMoveResponse:
		case PacketID::InstanceAreaTicketDiscard:

			// エリア移動かチケット破棄が通知されたら閉じる。
			Close();
			break;

	}
}
