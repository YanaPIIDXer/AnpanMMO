// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/NoticeData.h"

class MemoryStreamInterface;

DECLARE_DELEGATE_TwoParams(FOnRecvNotice, int32, const NoticeData &);

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
	void OnRecvNoticeList(MemoryStreamInterface *pStream);

	// 通知を受信した。
	void OnRecvNotice(MemoryStreamInterface *pStream);


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
