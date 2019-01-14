// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "NoticeManager.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketNoticeList.h"
#include "Packet/PacketReceiveNotice.h"

// コンストラクタ
NoticeManager::NoticeManager()
	: NextUuid(1)
{
}

// 通知リストを受信した。
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

// 通知を受信した。
bool NoticeManager::OnRecvNotice(MemoryStreamInterface *pStream)
{
	PacketReceiveNotice Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	AddNotice(Packet.Notice);

	return true;
}

// 通知リストを取得.
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

// 通知を消去.
void NoticeManager::RemoveNotice(uint32 Uuid)
{
	NoticeList.Remove(Uuid);
}


// 通知を追加.
void NoticeManager::AddNotice(const NoticeData &Data)
{
	int32 Uuid = NextUuid;
	NoticeList.Add(Uuid, Data);
	NextUuid++;

	OnRecvNoticeDelegate.ExecuteIfBound(Uuid, Data);
}
