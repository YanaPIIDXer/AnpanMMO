// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/NoticeData.h"

class MemoryStreamInterface;

DECLARE_DELEGATE_TwoParams(FOnRecvNotice, int32, const NoticeData &);

// 通知情報.
struct NoticeInformation
{

public:

	// UUID
	uint32 Uuid;

	// 通知データ
	NoticeData Data;

};

/**
 * 通知マネージャ
 */
class ANPANMMO_API NoticeManager
{

public:

	// コンストラクタ
	NoticeManager();

	// デストラクタ
	~NoticeManager() {}

	// 通知リストを受信した。
	bool OnRecvNoticeList(MemoryStreamInterface *pStream);

	// 通知を受信した。
	bool OnRecvNotice(MemoryStreamInterface *pStream);

	// 通知リストを取得.
	TArray<NoticeInformation> GetNoticeList() const;

	// 通知を消去.
	void RemoveNotice(uint32 Uuid);


	// 通知を受信した時のdelegate
	FOnRecvNotice OnRecvNoticeDelegate;

private:

	// 通知リスト
	TMap<int32, NoticeData> NoticeList;

	// 次に割り振られるUUID
	int32 NextUuid;


	// 通知を追加.
	void AddNotice(const NoticeData &Data);

};
