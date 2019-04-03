// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "MailManager.h"

// �R���X�g���N�^
MailManager::MailManager()
{
}

// �擾.
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

// ���[�����X�g����M�����B
void MailManager::OnRecvMailList(const FlexArray<MailData> &List)
{
	MailList.Empty();

	for (int i = 0; i < List.GetCurrentSize(); i++)
	{
		MailList.Add(List[i]);
	}
}

// �t���O�؂�ւ�
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
