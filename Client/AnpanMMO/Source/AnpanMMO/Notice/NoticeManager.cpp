// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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
bool NoticeManager::OnRecvNoticeList(MemoryStreamInterface *pStream)
{
	PacketNoticeList Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	for (int32 i = 0; i < Packet.Notices.GetCurrentSize(); i++)
	{
		AddNotice(Packet.Notices[i]);
	}

	return true;
}

// �ʒm����M�����B
bool NoticeManager::OnRecvNotice(MemoryStreamInterface *pStream)
{
	PacketReceiveNotice Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	AddNotice(Packet.Notice);

	return true;
}

// �ʒm���X�g���擾.
TArray<NoticeInformation> NoticeManager::GetNoticeList() const
{
	TArray<NoticeInformation> Notices;

	for (const auto KeyValue : NoticeList)
	{
		NoticeInformation Info;
		Info.Uuid = KeyValue.Key;
		Info.Data = KeyValue.Value;
		Notices.Add(Info);
	}

	return Notices;
}

// �ʒm������.
void NoticeManager::RemoveNotice(uint32 Uuid)
{
	NoticeList.Remove(Uuid);
}


// �ʒm��ǉ�.
void NoticeManager::AddNotice(const NoticeData &Data)
{
	int32 Uuid = NextUuid;
	NoticeList.Add(Uuid, Data);
	NextUuid++;

	OnRecvNoticeDelegate.ExecuteIfBound(Uuid, Data);
}
