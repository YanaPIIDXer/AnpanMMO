// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/MailData.h"
#include "FlexArray.h"

/**
 * ���[���Ǘ�.
 */
class ANPANMMO_API MailManager
{

public:

	// �R���X�g���N�^
	MailManager();

	// �f�X�g���N�^
	~MailManager() {}

	// �擾.
	bool Get(uint32 Id, MailData &OutData) const;

	// �S�Ẵ��[�����擾.
	const TArray<MailData> &GetAllMail() const { return MailList; }

	// ���[�����X�g����M�����B
	void OnRecvMailList(const FlexArray<MailData> &List);

	// �t���O�؂�ւ�
	void ChangeFlag(uint32 Id, uint8 Flag);

private:

	// ���[�����X�g
	TArray<MailData> MailList;

};
