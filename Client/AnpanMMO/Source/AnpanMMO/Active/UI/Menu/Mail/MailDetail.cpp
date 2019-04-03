// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "MailDetail.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketMailRead.h"
#include "Packet/PacketMailAttachmentRecvRequest.h"
#include "Packet/PacketMailAttachmentRecvResult.h"

// �R���X�g���N�^
UMailDetail::UMailDetail(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ���[�����J��
void UMailDetail::Open(const FMailData &InData)
{
	Data = InData;

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->ChangeMailFlag(Data.Id, MailData::Read);
	
	PacketMailRead Packet(Data.Id);
	pInst->SendPacket(&Packet);

	OnOpen();
}

// �p�P�b�g����M�����B
void UMailDetail::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case PacketID::MailAttachmentRecvResult:

			{
				PacketMailAttachmentRecvResult Packet;
				if (!Packet.Serialize(pStream)) { break; }

				if (Packet.Result == PacketMailAttachmentRecvResult::Success)
				{
					// �t���O�����������ĉ�ʂ��č\�z.
					Data.Flag = EMailFlag::RecvAttachment;
					OnOpen();
				}
			}
			break;
	}
}


// �Y�t����M�v���𑗐M.
void UMailDetail::SendRecvAttachmentRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketMailAttachmentRecvRequest Packet(Data.Id);
	pInst->SendPacket(&Packet);
}
