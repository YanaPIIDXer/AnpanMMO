// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NoticeManager.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketNoticeList.h"
#include "Packet/PacketReceiveNotice.h"

// �R���X�g���N�^
NoticeManager::NoticeManager()
{
}

// �ʒm���X�g����M�����B
void NoticeManager::OnRecvNoticeList(MemoryStreamInterface *pStream)
{
	PacketNoticeList Packet;
	Packet.Serialize(pStream);

	for (int32 i = 0; i < Packet.Notices.GetCurrentSize(); i++)
	{
		NoticeList.Add(Packet.Notices[i]);
	}
}

// �ʒm����M�����B
void NoticeManager::OnRecvNotice(MemoryStreamInterface *pStream)
{
	PacketReceiveNotice Packet;
	Packet.Serialize(pStream);

	UE_LOG(LogTemp, Log, TEXT("OnRecvNotice  Type:%d CustomerId:%d"), Packet.Notice.Type, Packet.Notice.CustomerId);

	NoticeList.Add(Packet.Notice);
}
