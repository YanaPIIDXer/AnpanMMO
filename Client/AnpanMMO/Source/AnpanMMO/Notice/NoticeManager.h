// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/NoticeData.h"

class MemoryStreamInterface;

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

private:

	// 通知リスト
	TArray<NoticeData> NoticeList;

};
