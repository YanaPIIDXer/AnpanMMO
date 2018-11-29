// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/NoticeData.h"

class MemoryStreamInterface;

/**
 * �ʒm�}�l�[�W��
 */
class ANPANMMO_API NoticeManager
{

public:

	// �R���X�g���N�^
	NoticeManager();

	// �f�X�g���N�^
	~NoticeManager() {}

	// �ʒm���X�g����M�����B
	void OnRecvNoticeList(MemoryStreamInterface *pStream);

	// �ʒm����M�����B
	void OnRecvNotice(MemoryStreamInterface *pStream);

private:

	// �ʒm���X�g
	TArray<NoticeData> NoticeList;

};
