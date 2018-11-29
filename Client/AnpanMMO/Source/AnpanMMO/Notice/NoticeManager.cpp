// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NoticeManager.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketNoticeList.h"
#include "Packet/PacketReceiveNotice.h"

// �R���X�g���N�^
NoticeManager::NoticeManager()
	: NextUuid(1)
{
}

// �ʒm���X�g����M�����B
void NoticeManager::OnRecvNoticeList(MemoryStreamInterface *pStream)
{
	PacketNoticeList Packet;
	Packet.Serialize(pStream);

	for (int32 i = 0; i < Packet.Notices.GetCurrentSize(); i++)
	{
		AddNotice(Packet.Notices[i]);
	}
}

// �ʒm����M�����B
void NoticeManager::OnRecvNotice(MemoryStreamInterface *pStream)
{
	PacketReceiveNotice Packet;
	Packet.Serialize(pStream);

	AddNotice(Packet.Notice);
}


// �ʒm��ǉ�.
void NoticeManager::AddNotice(const NoticeData &Data)
{
	int32 Uuid = NextUuid;
	NoticeList.Add(Uuid, Data);
	NextUuid++;

	OnRecvNoticeDelegate.ExecuteIfBound(Uuid, Data);
}
