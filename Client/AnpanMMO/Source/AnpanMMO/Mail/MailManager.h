// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/MailData.h"
#include "FlexArray.h"

/**
 * メール管理.
 */
class ANPANMMO_API MailManager
{

public:

	// コンストラクタ
	MailManager();

	// デストラクタ
	~MailManager() {}

	// 取得.
	bool Get(uint32 Id, MailData &OutData) const;

	// 全てのメールを取得.
	const TArray<MailData> &GetAllMail() const { return MailList; }

	// メールリストを受信した。
	void OnRecvMailList(const FlexArray<MailData> &List);

	// フラグ切り替え
	void ChangeFlag(uint32 Id, uint8 Flag);

private:

	// メールリスト
	TArray<MailData> MailList;

};
