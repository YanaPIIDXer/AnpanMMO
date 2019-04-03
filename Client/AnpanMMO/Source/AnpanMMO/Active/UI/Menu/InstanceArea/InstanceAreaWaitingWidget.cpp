// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "InstanceAreaWaitingWidget.h"

// �R���X�g���N�^
UInstanceAreaWaitingWidget::UInstanceAreaWaitingWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �p�P�b�g����M�����B
void UInstanceAreaWaitingWidget::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case PacketID::AreaMoveResponse:
		case PacketID::InstanceAreaTicketDiscard:

			// �G���A�ړ����`�P�b�g�j�����ʒm���ꂽ�����B
			Close();
			break;

	}
}
