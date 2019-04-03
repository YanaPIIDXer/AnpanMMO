// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "MailDetail.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketMailRead.h"
#include "Packet/PacketMailAttachmentRecvRequest.h"
#include "Packet/PacketMailAttachmentRecvResult.h"

// コンストラクタ
UMailDetail::UMailDetail(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// メールを開く
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

// パケットを受信した。
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
					// フラグを書き換えて画面を再構築.
					Data.Flag = EMailFlag::RecvAttachment;
					OnOpen();
				}
			}
			break;
	}
}


// 添付物受信要求を送信.
void UMailDetail::SendRecvAttachmentRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketMailAttachmentRecvRequest Packet(Data.Id);
	pInst->SendPacket(&Packet);
}
