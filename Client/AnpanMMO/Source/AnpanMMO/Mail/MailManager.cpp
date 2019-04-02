// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "MailManager.h"

// コンストラクタ
MailManager::MailManager()
{
}

// 取得.
bool MailManager::Get(uint32 Id, MailData &OutData) const
{
	for (int i = 0; i < MailList.Num(); i++)
	{
		if (MailList[i].Id == Id)
		{
			OutData = MailList[i];
			return true;
		}
	}

	return false;
}

// メールリストを受信した。
void MailManager::OnRecvMailList(const FlexArray<MailData> &List)
{
	MailList.Empty();

	for (int i = 0; i < List.GetCurrentSize(); i++)
	{
		MailList.Add(List[i]);
	}
}

// フラグ切り替え
void MailManager::ChangeFlag(uint32 Id, uint8 Flag)
{
	for (int i = 0; i < MailList.Num(); i++)
	{
		if (MailList[i].Id == Id)
		{
			MailList[i].Flag = Flag;
			return;
		}
	}
}
